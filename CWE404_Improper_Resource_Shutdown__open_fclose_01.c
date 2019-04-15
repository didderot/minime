/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_01.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-01.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: fclose
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <unistd.h>

#ifndef OMITBAD

void CWE404_Improper_Resource_Shutdown__open_fclose_01_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = open("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if (data != -1)
    {
        /* FLAW: Attempt to close the file using fclose() instead of close() */
        fclose((FILE *)data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = open("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if (data != -1)
    {
        /* FIX: Close the file using close() */
        close(data);
    }
}

void CWE404_Improper_Resource_Shutdown__open_fclose_01_good()
{
    goodB2G();
}

#endif /* OMITGOOD */
