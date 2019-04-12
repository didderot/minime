/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memcpy_01.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Sinks: type_overrun_memcpy
 *    GoodSink: Perform the memcpy() and prevent overwriting part of the structure
 *    BadSink : Overwrite part of the structure by incorrectly using the sizeof(struct) in memcpy()
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"
#include <wchar.h>

#define SRC_STR "0123456789abcdef0123456789abcde"

typedef struct _charVoid
{
    char charFirst[16];
    void * voidSecond;
    void * voidThird;
} charVoid;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memcpy_01_bad()
{
    {
        charVoid * structCharVoid = (charVoid *)malloc(sizeof(charVoid));
        if (structCharVoid == NULL) {exit(-1);}
        structCharVoid->voidSecond = (void *)SRC_STR;
        /* Print the initial block pointed to by structCharVoid->voidSecond */
        printLine((char *)structCharVoid->voidSecond);
        /* FLAW: Use the sizeof(*structCharVoid) which will overwrite the pointer y */
        memcpy(structCharVoid->charFirst, SRC_STR, sizeof(*structCharVoid));
        structCharVoid->charFirst[(sizeof(structCharVoid->charFirst)/sizeof(char))-1] = '\0'; /* null terminate the string */
        printLine((char *)structCharVoid->charFirst);
        printLine((char *)structCharVoid->voidSecond);
        free(structCharVoid);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        charVoid * structCharVoid = (charVoid *)malloc(sizeof(charVoid));
        if (structCharVoid == NULL) {exit(-1);}
        structCharVoid->voidSecond = (void *)SRC_STR;
        /* Print the initial block pointed to by structCharVoid->voidSecond */
        printLine((char *)structCharVoid->voidSecond);
        /* FIX: Use the sizeof(structCharVoid->charFirst) to avoid overwriting the pointer y */
        memcpy(structCharVoid->charFirst, SRC_STR, sizeof(structCharVoid->charFirst));
        structCharVoid->charFirst[(sizeof(structCharVoid->charFirst)/sizeof(char))-1] = '\0'; /* null terminate the string */
        printLine((char *)structCharVoid->charFirst);
        printLine((char *)structCharVoid->voidSecond);
        free(structCharVoid);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memcpy_01_good()
{
    good1();
}

#endif /* OMITGOOD */