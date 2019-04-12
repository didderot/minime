/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE367_TOC_TOU__access_01.c
Label Definition File: CWE367_TOC_TOU.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 367 Time-of-Check Time-Of-Use Race Condition
 * Sinks: access
 *    GoodSink: Open the file without checking the status information
 *    BadSink : Get status information on file using access(), open, write to, and close the file
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <unistd.h>
#define STAT stat
#define OPEN open
#define WRITE write
#define CLOSE close

#define BAD_SINK_STRING "Bad Sink..."
#define GOOD_SINK_STRING "Good Sink..."

#define ACCESS access

#ifndef OMITBAD

void CWE367_TOC_TOU__access_01_bad()
{
    {
        char filename[100] = "";
        int fileDesc = -1;
        if (fgets(filename, 100, stdin) == NULL)
        {
            printLine("fgets() failed");
            /* Restore NUL terminator if fgets fails */
            filename[0] = '\0';
        }
        if (strlen(filename) > 0)
        {
            filename[strlen(filename)-1] = '\0'; /* remove newline */
        }
        /* FLAW: Open and write to the file after checking the status information */
        if (ACCESS(filename, W_OK) == -1)
        {
            exit(1);
        }
        fileDesc  = OPEN(filename, O_RDWR);
        if (fileDesc == -1)
        {
            exit(1);
        }
        if (WRITE(fileDesc, BAD_SINK_STRING, strlen(BAD_SINK_STRING)) == -1)
        {
            exit(1);
        }
        if (fileDesc != -1)
        {
            CLOSE(fileDesc);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        char filename[100] = "";
        int fileDesc = -1;
        if (fgets(filename, 100, stdin) == NULL)
        {
            printLine("fgets() failed");
            /* Restore NUL terminator if fgets fails */
            filename[0] = '\0';
        }
        if (strlen(filename) > 0)
        {
            filename[strlen(filename)-1] = '\0'; /* remove newline */
        }
        /* FIX: Open the file without checking the status information */
        fileDesc  = OPEN(filename, O_RDWR);
        if (fileDesc == -1)
        {
            exit(1);
        }
        if (WRITE(fileDesc, GOOD_SINK_STRING, strlen(GOOD_SINK_STRING)) == -1)
        {
            exit(1);
        }
        if (fileDesc != -1)
        {
            CLOSE(fileDesc);
        }
    }
}

void CWE367_TOC_TOU__access_01_good()
{
    good1();
}

#endif /* OMITGOOD */
