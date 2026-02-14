#pragma once

typedef struct {
    int code;
} excode;

excode exitval = { 
    .code = 0 
};

excode errval    = { .code = 1   };
excode errval256 = { .code = 256 };

#define fetch return