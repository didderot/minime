/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__char_01.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-01.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: char Point data to a char data type
 * GoodSource: Point data to an int data type
 * Sink:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE843_Type_Confusion__char_01_bad()
{
    void * data;
    /* Initialize data */
    data = NULL;
    {
        /* FLAW: Point data to a char */
        char charBuffer = 'a';
        data = &charBuffer;
    }
    /* POTENTIAL FLAW: Attempt to access data as an int */
    printIntLine(*((int*)data));
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    void * data;
    /* Initialize data */
    data = NULL;
    {
        /* FIX: Point data to an int */
        int intBuffer = 8;
        data = &intBuffer;
    }
    /* POTENTIAL FLAW: Attempt to access data as an int */
    printIntLine(*((int*)data));
}

void CWE843_Type_Confusion__char_01_good()
{
    goodG2B();
}

#endif /* OMITGOOD */
