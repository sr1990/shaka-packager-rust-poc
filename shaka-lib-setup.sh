echo "1. Get shaka packager."
git submodule update --init --recursive
echo "2. Make build directory"
mkdir shaka-packager/build
echo "3. cd shaka-packager/build"
cd shaka-packager/build
echo "4. cmake"
cmake -DCMAKE_C_COMPILER=/usr/bin/clang-15 -DCMAKE_CXX_COMPILER=/usr/bin/clang++-15 -S .. -B .
echo "5. make"
make
echo "6. cd packager"
cd packager
echo "7. copy libshakapackager.mri to this folder"
cp ../../../libshakapackager.mri .
echo "8. ar -M <libshakapackager.mri"
ar -M <libshakapackager.mri
