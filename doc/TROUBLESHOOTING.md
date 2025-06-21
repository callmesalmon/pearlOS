# Troubleshooting pearlOS
This is the troubleshooting guide for pearlOS. In this guide you will learn about common errors
in pearlOS and how to fix them.

## Common errors and their solutions

### ``kernel/kernel.c:54:14: fatal error: 'debug.h' file not found``
There's a simple fix to this. You haven't ran ``./configure``. Running
``./configure`` will solve this error.

### ``ERROR: Kernel size [x] exceeds bootloader limit ([y] bytes) Increase``
### ``KERNEL_SIZE in boot/config.asm to at least [z] sectors``
You need to go into ``config/profiles/{your_profile}`` and change the value
``KERNEL_SIZE`` in ``config.asm`` to be ``z``. Then run ``./configure {your_profile}``
and you should be done. Under some circumstances this wont work, as increasing the
kernel size too much breaks the OS. Then you're sadly on your own :(