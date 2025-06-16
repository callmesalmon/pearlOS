# Style

These are the *official* style guidelines for pearlOS. They include *most*
of the languages included in the repo. Also, while the
[.editorconfig](https://github.com/callmesalmon/pearlOS/blob/main/.editorconfig) covers *most* of the things
covered here, it's important to keep in mind that not *all* of peoples code editors
support .editorconfigs. Some psychos also disable .editorconfigs on their code
editors. And with that, let's begin!

* [C Style](#c)
* [ASM Style](#asm)
* [Python Style](#python)
* [Make Style](#make)
* [Bash Style](#bash)
* [Perl Style](#perl)

# C
## General:
* Indent size: `4`
* Indent style: `space`
* Final newline: `false`
## Specifics:
* Brackets are *always*
on the *same* line as the
statement! We do not want
nor need this:
```c
int main()
{
    /* ... */
}
```
* In general, GNU style
should be avoided at all costs.

# ASM
## General:
* Indent size: `4`
* Indent style: `space`
* Final newline: `false`
## Specifics:
* Nothing here...

# Python
## General:
* Indent size: `4`
* Indent style: `space`
* Final newline: `true`
## Specifics:
* Make as minimal as possible.
We do not want to waste our project on
worthless scripting languages. We do *not*
need ``if __name__ == __main__:``, for
example. We *don't*.

# Make
## General:
* Indent size: `4`
* Indent style: `tab`
* Final newline: `false`
## Specifics:
* Nothing here...

# Bash
## General:
* Indent size: `4`
* Indent style: `space`
:wq
* Final newline: `false`
## Specifics:
* The preferred if-statement
should always be:
```sh
if [ x ]; then

fi

# Not, for example:
#
#     if x
#         then
#
#     fi
```
Which shall be used if nothing
else is necessary.

# Perl
## General:
* Indent size: `4`
* Indent style: `space`
* Final newline: `false`
## Specifics:
* Nothing here...