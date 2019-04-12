/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE459_Incomplete_Cleanup__char_01.c
Label Definition File: CWE459_Incomplete_Cleanup.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 459 Incomplete Cleanup
 * Sinks:
 *    GoodSink: Clean up properly
 *    BadSink : Don't unlink
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <unistd.h>
#define UNLINK unlink
#define FDOPEN fdopen
#define MKSTEMP mkstemp

#ifndef OMITBAD

void CWE459_Incomplete_Cleanup__char_01_bad()
{
    {
        char filename[] = "badXXXXXX";
        FILE *pFile;
        /* Establish that this is a temporary file and that it should be deleted */
        int fileDesc = MKSTEMP(filename);
        if (fileDesc != -1)
        {
            pFile = FDOPEN(fileDesc, "w");
            if (pFile != NULL)
            {
                fprintf(pFile, "Temporary file");
                fclose(pFile);
                /* FLAW: We don't unlink */
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        char filename[] = "goodXXXXXX";
        FILE *pFile;
        /* Establish that this is a temporary file and that it should be deleted */
        int fileDesc = MKSTEMP(filename);
        if (fileDesc != -1)
        {
            pFile = FDOPEN(fileDesc, "w");
            if (pFile != NULL)
            {
                fprintf(pFile, "Temporary file");
                fclose(pFile);
                /* FIX: Unlink the temporary file */
                UNLINK(filename); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
            }
        }
    }
}

void CWE459_Incomplete_Cleanup__char_01_good()
{
    good1();
}

#endif /* OMITGOOD */
