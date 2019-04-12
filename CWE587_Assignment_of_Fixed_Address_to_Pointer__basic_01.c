/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_01.c
Label Definition File: CWE587_Assignment_of_Fixed_Address_to_Pointer__basic.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 587 Assignment of Fixed Address to Pointer
 * Sinks:
 *    GoodSink: Assign the pointer to a stack variable
 *    BadSink : Assign fixed address to pointer
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_01_bad()
{
    {
        /* FLAW: Assigning fixed address to pointer */
        char *charPointer = (char*)0x400000;
        printHexCharLine(*charPointer);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        /* FIX: Assign the pointer to a stack variable */
        char charStack = 'a';
        char *charPointer = &charStack;
        printHexCharLine(*charPointer);
    }
}

void CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_01_good()
{
    good1();
}

#endif /* OMITGOOD */

