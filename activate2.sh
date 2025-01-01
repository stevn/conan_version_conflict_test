if [ "$(uname)" == "Darwin" ]; then
    echo "Activating macOS environment..."

    # Conan v2 home dir.
    export CONAN_HOME=$(pwd)/.conan2_mac

    if [[ $1 == new ]]; then
        conan2 profile detect --exist-ok --name default || exit 1
    fi

elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    echo "Activating Linux environment..."

    # Conan v2 home dir.
    export CONAN_HOME=$(pwd)/.conan2_linux

    if [[ $1 == new ]]; then
        conan2 profile detect --exist-ok --name default || exit 1
    fi

else
    echo "Unknown OS."
fi

echo "Env OK."
