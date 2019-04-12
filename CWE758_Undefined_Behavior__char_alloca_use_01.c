/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__char_alloca_use_01.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: alloca_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from alloca without initialization
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE758_Undefined_Behavior__char_alloca_use_01_bad()
{
    {
        char * pointer = (char *)ALLOCA(sizeof(char));
        char data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
        printHexCharLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        char data;
        char * pointer = (char *)ALLOCA(sizeof(char));
        data = 5;
        *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
        {
            char data = *pointer;
            printHexCharLine(data);
        }
    }
}

void CWE758_Undefined_Behavior__char_alloca_use_01_good()
{
    good1();
}

#endif /* OMITGOOD */
