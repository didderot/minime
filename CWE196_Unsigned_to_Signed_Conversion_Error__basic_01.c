/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE196_Unsigned_to_Signed_Conversion_Error__basic_01.c
Label Definition File: CWE196_Unsigned_to_Signed_Conversion_Error__basic.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 196 Unsigned To Signed Conversion Error
 * Sinks:
 *    GoodSink: Don't allow very large values of intUnsigned
 *    BadSink : Convert a possibly large unsigned int (larger than INT_MAX) to an int
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE196_Unsigned_to_Signed_Conversion_Error__basic_01_bad()
{
    {
        unsigned intUnsigned;
        int intSigned;
        intUnsigned = rand();
        if (rand() % 2 == 0)
        {
            intUnsigned = UINT_MAX - intUnsigned;
        }
        /* FLAW: intUnsigned could be very large, in which case intSigned will be negative */
        intSigned = intUnsigned;
        printIntLine(intSigned);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        unsigned intUnsigned;
        int intSigned;
        intUnsigned = rand();
        if (rand() % 2 == 0)
        {
            intUnsigned = UINT_MAX - intUnsigned;
        }
        /* FIX: don't allow very large values of intUnsigned */
        if (intUnsigned > INT_MAX)
        {
            exit(1);
        }
        intSigned = intUnsigned;
        printIntLine(intSigned);
    }
}

void CWE196_Unsigned_to_Signed_Conversion_Error__basic_01_good()
{
    good1();
}

#endif /* OMITGOOD */
