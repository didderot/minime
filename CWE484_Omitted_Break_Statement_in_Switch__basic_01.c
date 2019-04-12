/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE484_Omitted_Break_Statement_in_Switch__basic_01.c
Label Definition File: CWE484_Omitted_Break_Statement_in_Switch__basic.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 484 Omitted Break Statement in Switch
 * Sinks:
 *    GoodSink: Use breaks at the end of cases to prevent fall through
 *    BadSink : Missing break in first case
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE484_Omitted_Break_Statement_in_Switch__basic_01_bad()
{
    {
        int x = (rand() % 3);
        /* FLAW: Missing break in first case */
        switch (x)
        {
        case 0:
            printLine("0");
        case 1:
            printLine("1");
            break;
        case 2:
            printLine("2");
            break;
        default:
            printLine("Invalid Number");
            break;
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        int x = (rand() % 3);
        /* FIX: Use break in all cases that you do not intend "fall-through"
         * behavior */
        switch (x)
        {
        case 0:
            printLine("0");
            break;
        case 1:
            printLine("1");
            break;
        case 2:
            printLine("2");
            break;
        default:
            printLine("Invalid Number");
            break;
        }
    }
}

void CWE484_Omitted_Break_Statement_in_Switch__basic_01_good()
{
    good1();
}

#endif /* OMITGOOD */
