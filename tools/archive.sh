echo "Making zip image..."
zip dist/pearl-os-image.zip dist/os-image.bin
echo "Making tar image..."
tar -cvf dist/pearl-os-image.tar dist/os-image.bin
