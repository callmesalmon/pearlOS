echo "Making zip image..."
zip dist/pearlOS.zip dist/os-image.bin
echo "Making tar image..."
tar -cvf dist/pearlOS.tar dist/os-image.bin
