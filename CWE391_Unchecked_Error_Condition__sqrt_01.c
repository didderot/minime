/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__sqrt_01.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: sqrt
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if sqrt() failed
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#include <math.h>

#ifndef OMITBAD

void CWE391_Unchecked_Error_Condition__sqrt_01_bad()
{
    {
        double doubleNumber;
        doubleNumber = (double)sqrt((double)-1);
        /* FLAW: Do not check to see if sqrt() failed */
        printDoubleLine(doubleNumber);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        double doubleNumber;
        errno = 0; /* set errno to zero before calling sqrt(), which can change its value */
        doubleNumber = (double)sqrt((double)-1);
        /* FIX: Check errno to see if sqrt() failed */
        if (errno == EDOM)
        {
            printLine("sqrt() failed");
            exit(1);
        }
        printDoubleLine(doubleNumber);
    }
}

void CWE391_Unchecked_Error_Condition__sqrt_01_good()
{
    good1();
}

#endif /* OMITGOOD */
