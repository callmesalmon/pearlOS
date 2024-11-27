# pearlOS: Operating system
[![Build](https://img.shields.io/badge/Build-Passing-38C747?logo=github&labelColor=17181B)](/)
[![Version](https://img.shields.io/badge/Version-NET%2f2-FF0062?labelColor=17181B)](/)
[![C17](https://img.shields.io/badge/standard-C17-A8B9CC?logo=C&labelColor=17181B)](/)
[![BuildSys](https://img.shields.io/badge/standard-C17-0F6713?logo=GNU&labelColor=17181B&logoColor=0F6713)](/)  
pearlOS is an awesome operating system based of the [pidi-os](https://github.com/GandelXIV/pidi-os)
project that was sadly discontinued, but I *highly* recommend you to check out the new rust-based
operating system made by the same author; [RezOS](https://github.com/GandelXIV/RezOS)
But ofcourse only do that *after* you check out this project! pearlOS was made
for me to learn operating system things and also to become better at C and Assembly.

[![pearlOS](https://raw.githubusercontent.com/ElisStaaf/pearlOS/main/prod/boot.png)](https://github.com/ElisStaaf/pearlOS)

## Requirements

* [Make](https://www.gnu.org/software/make)
* [NASM](https://nasm.us)
* [GCC](https://gcc.gnu.org)
* [QEMU](https://www.qemu.org)

## Installation

> [!NOTE]
> Compilation is only guaranteed on linux with *GCC ISO C17*,
> but it is also possible in Windows with virtualization
> solutions like WSL (on Windows 11) or hyperV.

PearlOS prides itself in it's incredibly easy installation, as it only requires 3 commands!
It's very easy to install, firstly clone the repo:
```sh
git clone https://github.com/ElisStaaf/pearlOS
```
After going into the repo directory, run configure and then make:
```sh
./configure
make
```
Lastly, run the generated image at dist/pearl.bin:
```sh
qemu-system-i386 dist/pearl.bin
```
This will start up a QEMU session with the image, and you
can run the OS.

## Uninstalling

To uninstall, simply run:
```sh
make clean
```

## Contributing

If you want to contribute, you can. And if the contribution helps the OS in any way,
then I'll accept it. Yeah, nothing special, no "assignment contibutions".
