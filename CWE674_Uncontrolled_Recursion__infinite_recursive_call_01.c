/*
 * @description Uncontrolled Recursion
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static void helperBad()
{
    /* FLAW: this function causes infinite recursion */
    helperBad(); /* maintenance note: this may generate a warning, this is on purpose */
}

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_01_bad()
{
    helperBad();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void helperGood(unsigned level)
{
    /* FIX: provide lower-bound for recurssion stop */
    if (level == 0) 
    {
        return;
    }

    helperGood(level - 1);
}

static void good1()
{
    helperGood(5);
}

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_01_good()
{
    good1();
}

#endif /* OMITGOOD */
