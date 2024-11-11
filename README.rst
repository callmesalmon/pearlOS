OSk: Operating System kernel
============================
OSk is a *very* generic operating system kernel written in ASM and C. Currently only works for
x86_64, and to be honest; I haven't tested it yet so it might just... Not work.

Requirements
------------
* `Docker`_
* `Qemu`_

Installaton
-----------
To be honest, I don't really know how to build on any other operating system except linux, and
even for linux (since I haven't tested it yet) I kinda just guessed? So yeah, here are the
*linux* installation instructions:

.. code:: sh

   docker build buildenv -t osk
   docker run --rm -it -v "$(pwd)":/root/env osk
   make build-x86_64
   qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso

So yeah, contributions are of course *very* welcome, and remember; this is *very much* a WIP, so
don't judge my code *too* hard. But most importantly: Enjoy!

.. _`Docker`: https://www.docker.com
.. _`Qemu`: https://www.qemu.org
