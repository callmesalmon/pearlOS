> [!NOTE]
> pearlOS is no longer developed on github and is instead developed on
> [codeberg](https://codeberg.org/callmesalmon/pearlOS). The github version
> will still be up and all but it won't be updated.

# pearlOS: Operating system

[![Build](https://img.shields.io/github/actions/workflow/status/callmesalmon/pearlOS/ci.yml?logo=Github&labelColor=17181B&label=Build)](/)
[![C17](https://img.shields.io/badge/Standard-C17-A8B9CC?logo=C&labelColor=17181B)](/)
[![BuildSys](https://img.shields.io/badge/Build%20System-GNU%20Make-0F6713?logo=GNU&labelColor=17181B&logoColor=898484)](/)
[![Version](https://img.shields.io/badge/Version-Demon-FF0062?labelColor=17181B)](/)
[![Hippocratic License HL3-CORE](https://img.shields.io/static/v1?label=Hippocratic%20License&message=HL3-CORE&labelColor=5e2751&color=bc8c3d)](https://firstdonoharm.dev/version/3/0/core.html)  

pearlOS is an awesome operating system based of (and a continuation of) the discontinued
[pidi-os](https://github.com/GandelXIV/pidi-os). I *highly* recommend you to check out the new rust-based
operating system made by the [same author](https://github.com/GandelXIV);
[RezOS](https://github.com/GandelXIV/RezOS). pearlOS was made for me to learn operating system 
things and also to become better at C and Assembly. I am extremely inconsistent
in the way I update things and I kind of just implement things as I go so keep that in mind :P

[![pearlOS](https://github.com/callmesalmon/pearlOS/raw/main/prod/boot.png)](https://github.com/callmesalmon/pearlOS)  
*Warning: Image may be outdated.*

## Requirements

* [Make](https://www.gnu.org/software/make)
* [NASM](https://nasm.us)
* [Clang](https://clang.llvm.org/)
* [QEMU](https://www.qemu.org)
* [GRUB](https://www.gnu.org/software/grub/) 2.0 or later
* [xorriso](https://www.gnu.org/software/xorriso/)

## Compilation

> [!NOTE]
> Compilation is only guaranteed on Linux with *Clang ISO C17*,
> but it is also possible in Windows with virtualization
> solutions like WSL (on Windows 11) or hyperV.

### Prerequisites

On a Debian based OS (Debian, Ubuntu, Kali etc.):
```sh
sudo apt-get install build-essential clang nasm qemu grub2-common grub-pc-bin xorriso
```

### Building

To build the OS and create a bootable ISO:
```sh
make
```

#### Running in QEMU

To build and run the OS in QEMU:
```sh
make run # or "make qemu"
```

#### Creating a Bootable USB

1. Build the ISO:
```sh
make
```

2. Use `dd` to write the ISO to a USB drive (replace `/dev/sdX` with your USB device):
```sh
sudo dd if=build/pearlos.iso of=/dev/sdX bs=4M status=progress && sync
```

**WARNING:** Be very careful with the device name as this will erase all data on the target device.

### Troubleshooting

If you encounter any issues during the build process, please check the following:
1. Ensure all dependencies are installed
2. Check that you have sufficient disk space
3. Verify that your system meets the minimum requirements
4. Consult the [troubleshooting guide](/doc/TROUBLESHOOTING.md) for common issues

## Uninstalling

To uninstall, simply run:
```sh
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
but I can assure you, even if you see a 5-month pause, THE PROJECT IS NOT DEAD.
If the project dies, you can expect archival or at least a message.

## Documentation

The official pearlOS documentation can be viewed [here](/doc), but keep
in mind that I'm not that consistent on updating the documentation,
though it becomes pretty clear on what you have to do if you just...
rtfc (read the fucking code).

## License

This project is licensed under the [HL3-Core](https://firstdonoharm.dev/version/3/0/core.txt)
(Hippocratic License 3 Core) license. As long as you abide by the terms of the license, you can
use this software however you like.

## Developers
Since late June of 2025, pearlOS has been codeveloped by @callmesalmon and @androvonx95.
