#include <ctype.h>

int iscntrl(int c) {
    unsigned char uc = (unsigned char)c;
    return (uc <= 0x1F) || (uc == 0x7F);
}
