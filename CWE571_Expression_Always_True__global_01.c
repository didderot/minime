/*
 * @description Expression is always true via if (true_expression)
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE571_Expression_Always_True__global_01_bad() 
{
    /* FLAW: This expression is always true */
    if (globalTrue) 
    {
        printLine("Always prints");
    }
}

#endif /* OMITBAD */


#ifndef OMITGOOD

static void good1() 
{
    /* FIX: Possibly evaluate to false */
    if (globalReturnsTrueOrFalse() == globalTrue)
    {
        printLine("Sometimes prints");
    }
}

void CWE571_Expression_Always_True__global_01_good() 
{
    good1();
}

#endif /* OMITGOOD */
