/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__binary_if_01.c
Label Definition File: CWE476_NULL_Pointer_Dereference.pointflaw.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * Sinks: binary_if
 *    GoodSink: Do not check for NULL after the pointer has been dereferenced
 *    BadSink : Check for NULL after a pointer has already been dereferenced
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__binary_if_01_bad()
{
    {
        twoIntsStruct *twoIntsStructPointer = NULL;
        /* FLAW: Using a single & in the if statement will cause both sides of the expression to be evaluated
         * thus causing a NPD */
        if ((twoIntsStructPointer != NULL) & (twoIntsStructPointer->intOne == 5))
        {
            printLine("intOne == 5");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        twoIntsStruct *twoIntsStructPointer = NULL;
        /* FIX: Use && in the if statement so that if the left side of the expression fails then
         * the right side will not be evaluated */
        if ((twoIntsStructPointer != NULL) && (twoIntsStructPointer->intOne == 5))
        {
            printLine("intOne == 5");
        }
    }
}

void CWE476_NULL_Pointer_Dereference__binary_if_01_good()
{
    good1();
}

#endif /* OMITGOOD */
