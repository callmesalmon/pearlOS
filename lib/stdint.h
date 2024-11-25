#include "stddef.h"

#define __min(in) ( \
    (in >= 0) ? -in : in \
)

#define __max(in) ( \
    (in < 0) ? +in : in \
)

bool chint(char ch);
