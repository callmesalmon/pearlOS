#!/bin/bash

case $1 in 
    "--zip" | "-z")
        echo "Making zip image..."
        zip dist/pearl.zip dist/pearl.bin
        ;;

    "--tar" | "-t")
        echo "Making tar image..."
        tar -cvf dist/pearl.tar dist/pearl.bin
        ;;

    *)
        echo "Invalid option, please provide a valid flag."
        ;;
esac