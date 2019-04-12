/*
 * @description Unused code via 'return' before code
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE561_Dead_Code__return_before_code_01_bad() 
{
    return;
    /* FLAW: code after the 'return' */
    printLine("Hello");
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1() 
{
    /* FIX: Put code prior to return, or omit it */
    printLine("Hello");
    return;
}

void CWE561_Dead_Code__return_before_code_01_good() 
{
    good1();
}

#endif /* OMITGOOD */
