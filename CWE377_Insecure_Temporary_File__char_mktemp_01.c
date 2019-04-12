/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__char_mktemp_01.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: mktemp
 *    GoodSink: Create and open a temporary file more securely, with mkstemp()
 *    BadSink : Create and open a temporary file, created with mktemp(), insecurely
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#define OPEN open
#define CLOSE close
#define MKTEMP mktemp
#define MKSTEMP mkstemp

#ifndef OMITBAD

void CWE377_Insecure_Temporary_File__char_mktemp_01_bad()
{
    {
        char * filename;
        char tmpl[] = "fnXXXXXX";
        int fileDesc;
        filename = MKTEMP(tmpl);
        if (filename == NULL)
        {
            exit(1);
        }
        printLine(filename);
        /* FLAW: Open a temporary file using open() and flags that do not prevent a race condition */
        fileDesc = OPEN(filename, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fileDesc != -1)
        {
            printLine("Temporary file was opened...now closing file");
            CLOSE(fileDesc);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        char filename[] = "/tmp/fileXXXXXX"; // mutable store for filename
        // FIX: Use mkstemp(). This is not a perfect solution, since file
        // names are too predictable, but it is a vast improvement.
        int fileDesc = MKSTEMP(filename);
        printLine(filename);
        if (fileDesc != -1)
        {
            printLine("Temporary file was opened...now closing file");
            CLOSE(fileDesc);
        }
    }
}

void CWE377_Insecure_Temporary_File__char_mktemp_01_good()
{
    good1();
}

#endif /* OMITGOOD */
