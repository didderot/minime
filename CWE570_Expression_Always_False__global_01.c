/*
 * @description Expression is always false via if (false_expression)
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE570_Expression_Always_False__global_01_bad() 
{
    /* FLAW: This expression is always false */
    if (globalFalse) 
    {
        printLine("Never prints");
    }
}

#endif /* OMITBAD */


#ifndef OMITGOOD

static void good1() 
{
    /* FIX: Possibly evaluate to true */
    if (globalReturnsTrueOrFalse() == globalFalse)
    {
        printLine("Sometimes prints");
    }
}

void CWE570_Expression_Always_False__global_01_good() 
{
    good1();
}

#endif /* OMITGOOD */
