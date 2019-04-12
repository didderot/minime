#ifndef _STD_TESTCASE_H
#define _STD_TESTCASE_H

/* This file exists in order to:
 * 1) Include lots of standardized headers in one place
 * 2) To avoid #include-ing things in the middle of your code
 *    #include-ing in the middle of a C/C++ file is apt to cause compiler errors
 * 3) To get good #define's in place
 *
 * In reality you need a complex interaction of scripts of build processes to do
 * this correctly (i.e., autoconf)
 */

/* Linux/GNU wants this macro, otherwise stdint.h and limits.h are mostly useless */
#define __STDC_LIMIT_MACROS 1

#define ALLOCA alloca

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Define true and false, which are included in C++, but not in C */
#define true 1
#define false 0

/* rand only returns 15 bits, so we xor 3 calls together to get the full result (13 bits overflow, but that is okay) */
// shifting signed values might overflow and be undefined
#define URAND31() (((unsigned)rand()<<30) ^ ((unsigned)rand()<<15) ^ rand())
// choose to produce a positive or a negative number. Note: conditional only evaluates one URAND31
#define RAND32() ((int)(rand() & 1 ? URAND31() : -URAND31() - 1))

/* rand only returns 15 bits, so we xor 5 calls together to get the full result (11 bits overflow, but that is okay) */
// shifting signed values might overflow and be undefined
#define URAND63() (((uint64_t)rand()<<60) ^ ((uint64_t)rand()<<45) ^ ((uint64_t)rand()<<30) ^ ((uint64_t)rand()<<15) ^ rand())
// choose to produce a positive or a negative number. Note: conditional only evaluates one URAND63
#define RAND64() ((int64_t)(rand() & 1 ? URAND63() : -URAND63() - 1))

/* struct used in some test cases as a custom type */
typedef struct _twoIntsStruct
{
    int intOne;
    int intTwo;
} twoIntsStruct;

/* The variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their 
   initialized values. */
extern const int GLOBAL_CONST_TRUE; /* true */
extern const int GLOBAL_CONST_FALSE; /* false */
extern const int GLOBAL_CONST_FIVE; /* 5 */

/* The variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
extern int globalTrue; /* true */
extern int globalFalse; /* false */
extern int globalFive; /* 5 */

#include "std_testcase_io.h"

#endif
