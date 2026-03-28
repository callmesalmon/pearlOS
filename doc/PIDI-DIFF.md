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
* [types](https://github.com/callmesalmon/pearlOS/blob/main/lib/types.h)
  * Add a `NULL` value (`(void*)0`)
  * Add `size_t` type (`__SIZE_TYPE__`)
  * Add checks for if a value has been defined (`#ifdef` and others).
* [conv](https://github.com/callmesalmon/pearlOS/blob/main/lib/conv.h)
  * Add a `str_to_int` function (for userland cmd like `calc`)
  * Add more (and better) macros
* [io](https://github.com/callmesalmon/pearlOS/blob/main/lib/io.h)
  * Move to stdlib directory
  * Rename functions (`kprints` -> `puts`)
* [arrays](https://github.com/callmesalmon/pearlOS/blob/main/lib/arrays.h)
  * Add arrays.h
  * Add `len` macro (`sizeof(x) / sizeof(x[0])`)
* [mem](https://github.com/callmesalmon/pearlOS/blob/main/lib/mem.h)
  * Move to stdlib directory
  * Fix some comments
  * Format
  * Debug

Also added other, more insignificant things.

## Bug Fixes

### File sector patch
There was a very strange typecasting error regarding the ``Sector`` type which
inhibited my ability to build the project.
