/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__BUG_01.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: BUG
 *    GoodSink: Comments show no indications of bugs
 *    BadSink : Comment contains the word BUG
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE546_Suspicious_Comment__BUG_01_bad()
{
    /* FLAW: The following comment has the letters 'BUG' in it*/
    /* BUG: This comment has the letters 'BUG' in it, which is certainly
     * suspicious, because it could indicate this code has a BUG in it.
     */
    printLine("Hello");
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    /* FIX: Removed the suspicious comments */
    printLine("Hello");
}

void CWE546_Suspicious_Comment__BUG_01_good()
{
    good1();
}

#endif /* OMITGOOD */
