source activate2.sh
git clean -fx -e ".conan*" .
conan2 remove "*" -c
