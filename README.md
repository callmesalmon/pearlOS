# pearlOS: Operating system

[![Build](https://img.shields.io/github/actions/workflow/status/ElisStaaf/pearlOS/ci.yml?logo=Github&labelColor=17181B&label=Build)](/)
[![Version](https://img.shields.io/badge/Version-Dragonfly-FF0062?labelColor=17181B)](/)
[![C2x](https://img.shields.io/badge/Standard-C2x-A8B9CC?logo=C&labelColor=17181B)](/)
[![BuildSys](https://img.shields.io/badge/Build%20System-GNU%20Make-0F6713?logo=GNU&labelColor=17181B&logoColor=898484)](/)  

pearlOS is an awesome operating system based of the [pidi-os](https://github.com/GandelXIV/pidi-os)
project that was sadly discontinued, but I *highly* recommend you to check out the new rust-based
operating system made by the same author; [RezOS](https://github.com/GandelXIV/RezOS).
But ofcourse only do that *after* you check out this project! pearlOS was made
for me to learn operating system things and also to become better at C and Assembly.

[![pearlOS](https://github.com/ElisStaaf/pearlOS/raw/main/prod/boot.png)](https://github.com/ElisStaaf/pearlOS)

## Requirements

* [Make](https://www.gnu.org/software/make)
* [NASM](https://nasm.us)
* [GCC](https://gcc.gnu.org)
* [QEMU](https://www.qemu.org)

## Installation

> [!NOTE]
> Compilation is only guaranteed on linux with *GCC ISO C23*,
> but it is also possible in Windows with virtualization
> solutions like WSL (on Windows 11) or hyperV.

PearlOS prides itself in it's incredibly easy installation, as it only requires 3 commands!
It's very easy to install, firstly clone the repo:
```console
git clone https://github.com/ElisStaaf/pearlOS
```
After going into the repo directory, configure and then make:
```console
./configure
make
```
You can add your own config, just read [this](/doc/CONFIG.md)!  
Lastly, run the generated image at dist/pearl.bin  
by making the rule `qemu`:
```console
make qemu
```
This will start up a QEMU session with the image, and you
can run the OS.

## Uninstalling

To uninstall, simply run:
```console
make clean
```

## Differences

If you want to see the differences between pearlOS and [pidi-os](https://github.com/GandelXIV/pidi-os),
see [PIDI-DIFF.md](/doc/PIDI-DIFF.md).

## Contributing

I accept all meaningful contributions! As long as it doesn't break the
project, I'll probably accept your contribution.

## Activity

I'm a bit inconsistent on when I actually, y'know, maintain and update this,
but I can assure you, even if you see a 1-month pause, THE PROJECT IS NOT DEAD.
If the project dies, you can expect archival or at least a message.

## Documentation

The official pearlOS documentation can be viewed [here](/doc), but keep
in mind that I'm not that consistent on updating the documentation,
though it becomes pretty clear on what you have to do if you just...
rtfc (read the fucking code).

## License

Unless explicitly stated, every single *modified* file in this project is licensed
under the *Apache 2.0 License*, while the *unmodified* files are licensed under *MIT*.
The "SPDX-License-Identifier" rule obviously overrides this option, and is how you
explicitly state a different license. See [LICENSE](/LICENSE) for the 2 main licenses.