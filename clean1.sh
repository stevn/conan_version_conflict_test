source activate1.sh
git clean -fx -e ".conan*" .
conan1 remove "*" -f
