set -o xtrace

source activate1.sh || exit 1

# Build dependencies based on file types with API v1.
conan1 create advanced/file_types_v1 || exit 1
conan1 create advanced/file_io_v41 || exit 1
conan1 create advanced/file_mux || exit 1
conan1 create advanced/file_mux_feat || exit 1
conan1 create advanced/file_interface || exit 1

# Build super-project based on original state of dependencies
conan1 create advanced/super stevn/first --build missing || exit 1

# Build dependencies based on file types with API v2.
conan1 create advanced/file_types_v2 || exit 1
conan1 create advanced/file_io_v42 || exit 1

# Build super-project based on modified state of dependencies
# Even though we enable automatic building of missing dependencies,
# we expect this to fail with a version conflict
# due to file_types v1 vs. v2.
conan1 create advanced/super stevn/second --build missing || exit 1

echo "Wow, such success!"
