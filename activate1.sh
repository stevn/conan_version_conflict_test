if [ "$(uname)" == "Darwin" ]; then
    echo "Activating macOS environment..."

    # Conan v1 home dir.
    export CONAN_USER_HOME=$(pwd)/.conan_mac

    if [[ $1 == new ]]; then
        conan1 profile new --detect --force default || exit 1
        conan1 config set general.revisions_enabled=1 || exit 1
    fi

elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    echo "Activating Linux environment..."

    # Conan v1 home dir.
    export CONAN_USER_HOME=$(pwd)/.conan_linux

    if [[ $1 == new ]]; then
        conan1 profile new --detect --force default || exit 1
        conan1 profile update settings.compiler.libcxx=libstdc++11 default || exit 1
        conan1 config set general.revisions_enabled=1 || exit 1
    fi

else
    echo "Unknown OS."
fi

echo "Env OK."
