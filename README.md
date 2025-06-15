# pearlOS: Operating system

[![Build](https://img.shields.io/github/actions/workflow/status/ElisStaaf/pearlOS/ci.yml?logo=Github&labelColor=17181B&label=Build)](/)
[![Version](https://img.shields.io/badge/Version-Octopus-FF0062?labelColor=17181B)](/)
[![C17](https://img.shields.io/badge/Standard-C17-A8B9CC?logo=C&labelColor=17181B)](/)
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
* [Clang](https://clang.llvm.org/)
* [QEMU](https://www.qemu.org)

## Compilation

> [!NOTE]
> Compilation is only guaranteed on linux with *Clang ISO C17*,
> but it is also possible in Windows with virtualization
> solutions like WSL (on Windows 11) or hyperV.

Assuming you have the prerequisites installed and have a locally hosted version of the project (using tools like
git or others), you can compile and run the project using:
```sh
./configure && make qemu
```
This will start up a QEMU session with the image, and you can run the OS. If you don't have clang, you can
technically build the OS using GCC with ``sh scripts/gcc.sh``, but it is not recommended.

NOTE: To add your own config (and then run it using ``./configure``),
you can [read the docs](/doc/CONFIG.md).

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
but I can assure you, even if you see a 1-month pause, THE PROJECT IS NOT DEAD.
If the project dies, you can expect archival or at least a message.

## Documentation

The official pearlOS documentation can be viewed [here](/doc), but keep
in mind that I'm not that consistent on updating the documentation,
though it becomes pretty clear on what you have to do if you just...
rtfc (read the fucking code).

## License

This project is licensed under the ANTIFA-MIT license, which basically states that
the project is only available to non-fascists, and to the people which it is available
to, it is licensed under the MIT license.