typedef unsigned long uint32_t;
typedef unsigned char byte;
typedef unsigned char* bytes;
typedef unsigned int uint;
typedef unsigned short word;
typedef unsigned char bool;

#ifdef __SIZE_TYPE__
    typedef __SIZE_TYPE__ size_t;
#else
    #error "[ERROR]: __SIZE_TYPE__ is not defined. Can't compile."
#endif

#if !defined(true) && !defined(false)
#    define true (bool) 1
#    define false (bool) 0
#endif

#ifndef NULL
#    define NULL ((void*)0)
#endif

#if !defined(low_16) && !defined(high_16)
#    define low_16(address) (word)((address) & 0xFFFF)
#    define high_16(address) (word)(((address) >> 16) & 0xFFFF)
#endif
