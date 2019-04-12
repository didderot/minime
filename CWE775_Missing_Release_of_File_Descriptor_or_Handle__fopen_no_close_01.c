/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_01.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-01.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_01_bad()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = fopen("BadSource_fopen.txt", "w+");
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = fopen("BadSource_fopen.txt", "w+");
    /* FIX: If the file is still opened, close it */
    if (data != NULL)
    {
        fclose(data);
    }
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_01_good()
{
    goodB2G();
}

#endif /* OMITGOOD */
