/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01.c
Label Definition File: CWE468_Incorrect_Pointer_Scaling.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 468 Incorrect Pointer Scaling
 * Sinks: char_ptr_to_int
 *    GoodSink: Correctly use sizeof() for pointer scaling
 *    BadSink : Do not use sizeof() in pointer scaling
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01_bad()
{
    {
        int intArray[5] = { 1, 2, 3, 4, 5 };
        char *charPointer = (char *)intArray; /* get a char pointer to intArray - common idiom in file and network packet parsing */
        /* get intArray[2] */
        /* FLAW: sizeof() needed since pointer is a char*, not an int* */
        int toPrint = (int) (*(charPointer+2));
        printIntLine(toPrint);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        int intArray[5] = { 1, 2, 3, 4, 5 };
        char *charPointer = (char *)intArray; /* get a char pointer to intArray - common idiom in file and network packet parsing */
        /* get intArray[2] */
        /* FIX: add *sizeof(int) to account for the difference in pointer types */
        int toPrint = (int) (*(charPointer+(2*sizeof(int))));
        printIntLine(toPrint);
    }
}

void CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01_good()
{
    good1();
}

#endif /* OMITGOOD */
