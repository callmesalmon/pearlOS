pearlOS: Operating System
============================
.. image:: https://img.shields.io/badge/Build%20(fedora)-passing-2a7fd5?logo=fedora&logoColor=2a7fd5&style=for-the-badge
   :alt: Build = Passing
   :target: https://github.com/ElisStaaf/pearlOS
.. image:: https://img.shields.io/badge/Version-386Pearl-38c747?style=for-the-badge
   :alt: Version = 386Pearl
   :target: https://github.com/ElisStaaf/pearlOS
.. image:: https://img.shields.io/badge/Language-C-grey?logo=c&logoColor=white&labelColor=blue&style=for-the-badge
   :alt: Language = C
   :target: https://github.com/ElisStaaf/pearlOS
.. image:: https://img.shields.io/badge/LOC%20(counted%20by%20cloc)-~2000-e11e5f?style=for-the-badge
   :alt: LOC = ~200
   :target: https://github.com/ElisStaaf/pearlOS

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
