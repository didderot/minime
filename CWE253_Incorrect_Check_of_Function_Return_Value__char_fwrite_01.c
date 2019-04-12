/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fwrite
 *    GoodSink: Correctly check if fwrite() failed
 *    BadSink : Incorrectly check if fwrite() failed
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01_bad()
{
    /* FLAW: fwrite() might fail, in which case the return value will not be equal to strlen(data),
     * but we are checking to see if the return value is less than 0 */
    if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) < 0)
    {
        printLine("fwrite failed!");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    /* FIX: check for the correct return value */
    if (fwrite((char *)"string", sizeof(char), strlen("string"), stdout) != strlen("string"))
    {
        printLine("fwrite failed!");
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fwrite_01_good()
{
    good1();
}

#endif /* OMITGOOD */
