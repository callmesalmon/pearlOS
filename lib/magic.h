#pragma once

#include "stdint.h"

#define len(arr) ( \
    sizeof(arr) / sizeof(*arr) \
)

#define min(in) (__min(in))
#define max(in) (__max(in))
