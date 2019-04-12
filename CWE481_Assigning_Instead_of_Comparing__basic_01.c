/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE481_Assigning_Instead_of_Comparing__basic_01.c
Label Definition File: CWE481_Assigning_Instead_of_Comparing__basic.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 481 Assigning Instead of Comparing
 * Sinks:
 *    GoodSink: Comparing
 *    BadSink : Assigning instead of comparing
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE481_Assigning_Instead_of_Comparing__basic_01_bad()
{
    {
        int intRand = rand();
        /* FLAW: should be == and INCIDENTIAL CWE 571 Expression Is Always True */
        if(intRand = 5)
        {
            printLine("i was 5");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        int intRand = rand();
        /* FIX: used == instead of = */
        if(intRand == 5)
        {
            printLine("i was 5");
        }
    }
}

void CWE481_Assigning_Instead_of_Comparing__basic_01_good()
{
    good1();
}

#endif /* OMITGOOD */

