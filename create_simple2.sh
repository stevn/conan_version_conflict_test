set -e

source activate2.sh new

pushd simple/common_v1
conan2 create . --build missing
popd

pushd simple/common_v2
conan2 create . --build missing
popd

pushd simple/direct
conan2 create . --build missing
popd

pushd simple/super
conan2 create . --build missing
popd

echo "Wow, such success!"
