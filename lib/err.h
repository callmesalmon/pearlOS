/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

/* [OLD/NEW]
 * Old exit codes are just like
 * every other thing, but the
 * *new* exit codes have a 
 * special type, and you
 * can access the function exit
 * code by using "func.code",
 * e.g: myfunc().code. Define
 * EXIT_OLD if you want the old
 * experience, though it is gone.
 */

#pragma once

/* Base exit code */
#ifndef EXIT_OLD
    typedef struct {
        int code;
    } excode;
#endif

/* Regular 'ol exit success */
#ifdef EXIT_OLD
#   define exitval 0
#else
    excode exitval = {
        .code = 0
    };
#endif

/* Old and new standard error */
#ifdef EXIT_OLD
#   define errval 1
#else
    excode errval = {
        .code = 1
    };
#endif

/* Another one for good measure */
#ifdef EXIT_OLD
#   define errval256 256
#else
    excode errval256 = {
        .code = 256
    };
#endif

/* Exit macro */
#ifdef EXIT_OLD
#   define fetch return
#else
#   define fetch(c) return c;
#endif