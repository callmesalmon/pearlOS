# Pidi-Diff

There are many differences between [pidi-os](https://github.com/GandelXIV/pidi-os),
these are listed below in the form of:

* [Additions](#additions)
* [Bug Fixes](#bug-fixes)

## Additions

Many more extra commands for the userland, such as:
* [fortune](https://github.com/callmesalmon/pearlOS/blob/main/kernel/cmd/fortune.h)
* [panic](https://github.com/callmesalmon/pearlOS/blob/main/kernel/cmd/panic.h)
* [alloc](https://github.com/callmesalmon/pearlOS/blob/main/kernel/cmd/alloc.h)
* [memstat](https://github.com/callmesalmon/pearlOS/blob/main/kernel/cmd/memstat.h)
* [calc](https://github.com/callmesalmon/pearlOS/blob/main/kernel/cmd/calc.h)
* [kowsay](https://github.com/callmesalmon/pearlOS/blob/main/kernel/cmd/kowsay.h)

Additions for already existing commands, such as:
* [pearlfetch](https://github.com/callmesalmon/pearlOS/blob/main/kernel/cmd/pearlfetch.h)\*
\*: Has been renamed.

Other things have been added to the userland, such as:
* comments (start with ";")
* *better* theming
* more themes

The userland has also been *slightly* modified, including:
* prompt (which is now "%")
* renamed commands

The [scripts](https://github.com/callmesalmon/pearlOS/blob/main/scripts) (on pidi: tools) folder has
also been modified, modifications include:
* remove useless timing and archiving script
* minimalize [gencolours.py](https://github.com/callmesalmon/pearlOS/blob/main/scripts/gencolours.py)\*
\*: Has been renamed (color -> colour)

The [stdlib](https://github.com/callmesalmon/pearlOS/blob/main/lib) of the project has been greatly
improved, changes include:
* [math](https://github.com/callmesalmon/pearlOS/blob/main/lib/math.h)
  * Add infinity, being `x/0`
* [stddef](https://github.com/callmesalmon/pearlOS/blob/main/lib/stddef.h)
  * Add a `NULL` value (`(void*)0`)
  * Add `size_t` type (`__SIZE_TYPE__`)
  * Add checks for if a alue has been defined (`#ifdef` and others).
* [conv](https://github.com/callmesalmon/pearlOS/blob/main/lib/conv.h)
  * Add a `str_to_int` function (for userland cmd like `calc`)
  * Add more (and better) macros
* [io](https://github.com/callmesalmon/pearlOS/blob/main/lib/io.h)
  * Move to stdlib directory
  * Rename functions (`kprints` -> `puts`)
* [magic](https://github.com/callmesalmon/pearlOS/blob/main/lib/magic.h)
  * Add magic.h
  * Add `len` macro (`sizeof(x) / sizeof(x[0])`)
* [mem](https://github.com/callmesalmon/pearlOS/blob/main/lib/mem.h)
  * Move to stdlib directory
  * Fix some comments
  * Format
  * Debug

Also added other, more insignificant things.

A better [configuration](https://github.com/callmesalmon/pearlOS/blob/main/config)
was added. It operates using "profiles" and these "profiles" include different
configuration files. These are:
* [config.h](https://github.com/callmesalmon/pearlOS/blob/main/config/config.h)
  * Includes the kernel config.
  * The only C file of the group.

A prototype of a working text editor (e.g superior ``to`` command), is being actively
worked on, mainly by "androvonx95". It is called zeptex and is found in the "zeptex"
folder. Keep in mind that this is a downstream version of
[https://github.com/androvonx95/Zeptex](https://github.com/androvonx95/Zeptex), so
for the most recent updates, you should probably look over there.

## Bug Fixes

### File sector patch
I *needed* to be able to run the project, I couldn't have a non-functional
OS as my most prideful project, right? But when I tried compiling with `gcc`
(`gnu17` if you're wondering), it didn't work. Instead, gcc screamed at me
about "invalid types" and other shit. So I looked at the problematic
code, here it is:
```c
Sector* init_sector() {
    /* ... */
}

Sector* fs = init_sector();
```
What. The. Fuck. Basically what gcc was saying was that I couldn't assign
object of type `Sector*` A.K.A `SectorStruct*` to object of type `Sector*`.
Basically, gcc's thought process was:
```c

Sector* fs = init_sector();
↪ Sector* fs = Sector* init_sector() { /* ... */ };
  ↪ Sector* fs = {returnValue};
    ↪ Sector* = SectorStruct*;
      Sector* fs = (SectorStruct*)init_sector();
```
GCC thinks "Wait! Isn't `Sector*` = `SectorStruct*`? Yes! Changing...", but for
*some* reason it didn't register this with the variable type. This can be easily
solved by typecasting, but it took me a while to fix.
```c
Sector* fs = (Sector*)init_sector();
```

### Patch bootloader limits (issue [18](https://github.com/callmesalmon/pearlOS/issues/18))
The custom bootloader is fine and all (I guess), but it has its limits. The truth is that
the pearlOS kernel had been just barely working for a while, and it's because all 33 sectors
were completely filled with stuff:

```asm
KERNEL_SIZE db  33 ; This was all filled eventually
```

Androvonx's [pull 19](https://github.com/callmesalmon/pearlOS/pull/19)
fixed this for a while by increasing kernel size limits, but it was clear that it was not
enough. Eventually we found a workaround, and it was just by eliminating the custom bootloader
entirely and using a tool like grub for loading instead. We did just that and the issue was
solved. The bootloader of the past can be found in 
[callmesalmon/pearlboot](https://github.com/callmesalmon/pearlboot).