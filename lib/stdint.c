#include "stdint.h"
#include "stddef.h"

bool chint(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || 
        (ch >= 'A' && ch <= 'Z'))
    {
        return false;
    }
    return true;
}
