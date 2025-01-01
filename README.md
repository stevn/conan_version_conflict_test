# Conan package versions conflicts test

This project tries to reproduce a Conan package version conflict.

## Setup

Install conan v1 and v2 clients in parallel (e.g. by downloading portable versions from github releases page and putting them in the path) and create some symlinks so that `conan1` command points to latest conan version 1 client and `conan2` command points to latest conan version 2 client.

```text
conan1 --version
source activate1.sh new
conan1 config home

conan2 --version
source activate2.sh new
conan2 config home
```

## Simple scenario

The problem could not be reproduced in this simple scenario.

- Run `./create_simple1.sh` for Conan v1 testing of the simple scenario.
- Run `./create_simple2.sh` for Conan v2 testing of the simple scenario.

### Requirements overview

This dependency tree works OK:

```text
super/1.0.0
- direct/[^1.0.0]
- common/[^1.0.0]

direct/1.0.0
- common/[^1.0.0]
```

But this shall lead to a package version conflict:

```text
super/1.0.0
- direct/[^1.0.0]
- common/[^1.0.0]

direct/1.0.0
- common/[^2.0.0]
```

### Error handling in Conan v1 and Conan v2

This type of version conflict shall be caught by the package manager before a compiler / linker failure - or even undefined behavior - happens.

In Conan 1 we get this response:

```text
ERROR: Version range '^2.0.0' required by 'direct/1.0.0' not valid for downstream requirement 'common/1.0.0'
````

In Conan 2 we get this response:

```text
ERROR: Version conflict: Conflict between common/[^2.0.0] and common/1.0.0 in the graph.
Conflict originates from direct/1.0.0

Run 'conan graph info ... --format=html > graph.html' and open 'graph.html' to inspect the conflict graphically.
```

So in this simple scenario this works correctly in both Conan v1 and Conan v2.

Now let's try harder to reproduce the "advanced" problem.

## Advanced scenario

The problem is hard to reproduce and requires an advanced dependencies scenario.

- Run `./create_advanced1.sh` for Conan v1 testing of the advanced scenario.
- Run `./create_advanced2.sh` for Conan v2 testing of the advanced scenario.

### Requirements overview

We need to reproduce this dependency tree:

```text
super v1.0.0 (conanfile.txt)
- file_interface/[4.1.1]@stevn/stable
- file_types/1.1.0@stevn/stable
- file_mux/8.0.1@stevn/feature


file_interface/4.1.1@stevn/stable
- file_types/[^1.1.0]@stevn/stable
- file_mux/[^8.0.0]@stevn/stable -> overridden to file_mux/8.0.1@stevn/feature by super-project


file_mux/8.0.1@stevn/stable
- file_io/[^4.0.0]@stevn/stable
- file_types/[^1.0.1]@stevn/stable

file_mux/8.0.1@stevn/feature
- file_io/[^4.0.0]@stevn/stable resolved to file_io/4.2.0@stevn/stable
- file_types/[^1.0.1]@stevn/stable


file_io/4.1.0@stevn/stable
- file_types/[^1.0.0]@stevn/stable

file_io/4.2.0@stevn/stable
- file_types/[^2.0.0]@stevn/stable


file_types/1.1.0@stevn/stable
- no deps

file_types/2.0.0@stevn/stable
- no deps
```

The basic problem is that first the file_types package existed in versions 1.0.0, 1.0.1, and 1.1.0 which all are compatible. Then there was an API break when file_types v2.0.0 was released. By using the version range `[^1.0.0]` this new version isn't used by default, so in theory that should not be a problem. However, the dependency tree is slightly more complex: a new version 4.2.0 of file_io package is built, which requires version 2.0.0 of file_types. This means it is incompatible on a package level. It is probably a mistake in the versioning. It probably should have been created as version file_io/5.0.0 instead of file_io/4.2.0 to prevent package version conflicts regarding its dependency on the file_types package.

Anyway, let's assume that this is the current state of things, and let's now examine how Conan version 1 and version 2 handle this situation.

### Error handling in Conan v1

We have reproduced the original problem which was observed with Conan v1.

When running `create_advanced1.sh` the following warning appears somewhere in the log while it is building super-project based on new API v2 of file_types.

```text
WARN: file_io/4.2.0@stevn/stable: requirement file_types/[^2.0.0]@stevn/stable overridden by file_mux/8.0.1@stevn/feature to file_types/1.1.0@stevn/stable
```

Then, during compilation of file_io/4.2.0 (triggered via `--build missing` of the super-project) the new API v2 cannot be found by the compiler:

```text
[ 50%] Building CXX object CMakeFiles/file_io.dir/src/file_io.cpp.o
/home/pop/source/conan_version_test2/.conan_linux/.conan/data/file_io/4.2.0/stevn/stable/build/aa4d024de2ee3ff5205d420c37aaeb2804b0f3f5/src/file_io.cpp: In function ‘void file_io()’:
/home/pop/source/conan_version_test2/.conan_linux/.conan/data/file_io/4.2.0/stevn/stable/build/aa4d024de2ee3ff5205d420c37aaeb2804b0f3f5/src/file_io.cpp:8:5: error: ‘file_types_v2’ was not declared in this scope; did you mean ‘file_types’?
    8 |     file_types_v2();
      |     ^~~~~~~~~~~~~
      |     file_types
gmake[2]: *** [CMakeFiles/file_io.dir/build.make:76: CMakeFiles/file_io.dir/src/file_io.cpp.o] Error 1
```

This error condition was not caught correctly by Conan 1. We were lucky that the error condition was caught by the compiler though.

### Error handling in Conan v2

Yay, in Conan version 2 this seems to be fixed! There the version conflict is correctly identified as such when running `./create_advanced2.sh`:

```text
ERROR: Version conflict: Conflict between file_types/[^2.0.0]@stevn/stable and file_types/1.1.0@stevn/stable in the graph.
Conflict originates from file_io/4.2.0@stevn/stable
```

So, it seems that this problem can be seen as solved in Conan v2.
