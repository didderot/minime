/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__char_pointer_01.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-01.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__char_pointer_01_bad()
{
    char * data;
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
    /* POTENTIAL FLAW: Use data without initializing it */
    printLine(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    /* FIX: Initialize data */
    data = "string";
    /* POTENTIAL FLAW: Use data without initializing it */
    printLine(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
    /* FIX: Ensure data is initialized before use */
    data = "string";
    printLine(data);
}

void CWE457_Use_of_Uninitialized_Variable__char_pointer_01_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */
