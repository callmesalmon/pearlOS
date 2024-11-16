#!/bin/sh

case $1 in 
    "--zip" | "-z")
        echo "Making zip image..."
        zip dist/pearlOS.zip dist/os-image.bin
        ;;

    "--tar" | "-t")
        echo "Making tar image..."
        tar -cvf dist/pearlOS.tar dist/os-image.bin
        ;;

    *)
        echo "Invalid option, please provide a valid flag."
        ;;
esac
