/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__addition_01.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: addition
 *    GoodSink: Adding two ints and storing the result
 *    BadSink : Adding two ints but not storing the result has no effect
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE398_Poor_Code_Quality__addition_01_bad()
{
    {
        int intOne = 1, intTwo = 1, intSum = 0;
        printIntLine(intSum);
        /* FLAW: the statement has no effect */
        intOne + intTwo; /* This generates a compiler warning, but we expect it to */
        printIntLine(intSum);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        int intOne = 1, intTwo = 1, intSum = 0;
        printIntLine(intSum);
        /* FIX: Do not include a statement that has no effect */
        intSum = intOne + intTwo;
        printIntLine(intSum);
    }
}

void CWE398_Poor_Code_Quality__addition_01_good()
{
    good1();
}

#endif /* OMITGOOD */
