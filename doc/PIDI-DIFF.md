# Pidi-Diff

There are many differences between [pidi-os](https://github.com/GandelXIV/pidi-os),
these are listed below in the form of:

* [Additions](#additions)
* [Bug Fixes](#bug-fixes)

## Additions

Many more extra commands for the userland, such as:
* [loop](https://github.com/ElisStaaf/pearlOS/blob/main/kernel/programs/loop.h)
* [fortune](https://github.com/ElisStaaf/pearlOS/blob/main/kernel/programs/fortune.h)
* [panic](https://github.com/ElisStaaf/pearlOS/blob/main/kernel/programs/panic.h)
* [alloc](https://github.com/ElisStaaf/pearlOS/blob/main/kernel/programs/alloc.h)
* [memstat](https://github.com/ElisStaaf/pearlOS/blob/main/kernel/programs/memstat.h)
* [calc](https://github.com/ElisStaaf/pearlOS/blob/main/kernel/programs/calc.h)

Additions for already existing commands, such as:
* [pearlfetch](https://github.com/ElisStaaf/pearlOS/blob/main/kernel/programs/pearlfetch.h)\*
\*: Has been renamed.

Other things have been added to the userland, such as:
* comments (start with "#")
* *better* theming
* more themes

The userland has also been *slightly* modified, including:
* prompt (\*)
* renamed commands

The [scripts](https://github.com/ElisStaaf/pearlOS/blob/main/scripts) folder has also been modified,
modifications include:
* remove useless timing script
* minimalize [gencolours.py](https://github.com/ElisStaaf/pearlOS/blob/main/scripts/gencolours.py)\*
* update [archive.sh](https://github.com/ElisStaaf/pearlOS/blob/main/scripts/archive.sh)
\*: Has been renamed (color -> colour)

The [stdlib](https://github.com/ElisStaaf/pearlOS/blob/main/lib) of the project has been greatly
improved, changes include:
* [math](https://github.com/ElisStaaf/pearlOS/blob/main/lib/math.h)
  * Add more mathematical constants, like `e` and `π`
  * Add infinity, being `x/0`
  * Add a factorial function
* [stddef](https://github.com/ElisStaaf/pearlOS/blob/main/lib/stddef.h)
  * Add a `NULL` value (`(void*)0`)
  * Add `size_t` type (`__SIZE_TYPE__`)
  * Add checks for if a alue has been defined (`#ifdef` and others).
* [conv](https://github.com/ElisStaaf/pearlOS/blob/main/lib/conv.h)
  * Add a `str_to_int` function (for userland programs like `calc`)
  * Add more (and better) macros
* [io](https://github.com/ElisStaaf/pearlOS/blob/main/lib/io.h)
  * Move to stdlib directory
  * Rename functions (`kprints` -> `puts`)
* [magic](https://github.com/ElisStaaf/pearlOS/blob/main/lib/magic.h)
  * Add magic.h
  * Add `len` macro (`sizeof(x) / sizeof(*x)`)
* [stdint](https://github.com/ElisStaaf/pearlOS/blob/main/lib/stdint.h)
  * Add stdint.h
  * Add `chint` function (is `char` also valid `int`?)
* [mem](https://github.com/ElisStaaf/pearlOS/blob/main/lib/mem.h)
  * Move to stdlib directory
  * Fix some comments
  * Format
  * Debug

Also added other, more insignificant things to for example
[boot](https://github.com/ElisStaaf/pearlOS/blob/main/boot).

A better [configuration](https://github.com/ElisStaaf/pearlOS/blob/main/config)
was added. It operates using "profiles" and these "profiles" include different
configuration files. These are:
* [config.h](https://github.com/ElisStaaf/pearlOS/blob/main/config/config.h)
  * Includes the kernel config.
  * The only C file of the group.
* [config.asm](https://github.com/ElisStaaf/pearlOS/blob/main/config/config.asm)
  * Configs the boot sector.
  * Error messages.
* [kentry.asm](https://github.com/ElisStaaf/pearlOS/blob/main/config/kentry.asm)
  * Configs the entry.
  * Maybe don't... Touch this one..?

## Bug Fixes

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