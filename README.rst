pearlOS: Operating System
============================
pearlOS is an awesome operating system based of the `pidiOS`_ project that was
sadly discontinued, but I *highly* recommend you to check out the new rust-based
operating system made by the same author: `RezOS`_.

Requirements
------------
* `Make`_
* `QEMU`_

Installation
------------
To be honest, I don't really know how to build on any other operating system except linux, and
even for linux (since I haven't tested it yet) I kinda just guessed? So yeah, here are the
*linux* installation instructions:

   .. code:: sh

   make gcc nasm
   qemu

So yeah, contributions are of course *very* welcome, and remember; this is *very much* a WIP, so
don't judge my code *too* hard. But most importantly: Enjoy!

.. _`pidiOS`: https://github.com/GandelXIV/pidi-os
.. _`RezOS`: https://github.com/GandelXIV/RezOS
.. _`Make`: https://www.gnu.org/software/make
.. _`QEMU`: https://www.qemu.org
