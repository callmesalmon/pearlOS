# Troubleshooting pearlOS
This is the troubleshooting guide for pearlOS. In this guide you will learn about common errors
in pearlOS and how to fix them.

## Common errors and their solutions

### ``kernel/kernel.c:54:14: fatal error: 'debug.h' file not found``
There's a simple fix to this. You haven't ran ``./configure``. Running
``./configure`` will solve this error.