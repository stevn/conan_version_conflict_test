set -e

source activate1.sh new

pushd simple/common_v1
conan1 create . --build missing
popd

pushd simple/common_v2
conan1 create . --build missing
popd

pushd simple/direct
conan1 create . --build missing
popd

pushd simple/super
conan1 create . --build missing
popd

echo "Wow, such success!"
