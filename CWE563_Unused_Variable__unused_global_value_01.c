/*
 * @description Unused global value
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

int CWE563_Unused_Variable__unused_global_value_01_badGlobal = 0;

void CWE563_Unused_Variable__unused_global_value_01_bad() 
{
    /* FLAW: Overwrite the initial value of the global variable before use */
    CWE563_Unused_Variable__unused_global_value_01_badGlobal = 10;
    printIntLine(CWE563_Unused_Variable__unused_global_value_01_badGlobal);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

int CWE563_Unused_Variable__unused_global_value_01_globalGood1 = 5;

static void good1() 
{
    /* FIX: Do not overwrite the value of the global variable before use */
    printIntLine(CWE563_Unused_Variable__unused_global_value_01_globalGood1);
}

void CWE563_Unused_Variable__unused_global_value_01_good() 
{
    good1();
}

#endif /* OMITGOOD */
