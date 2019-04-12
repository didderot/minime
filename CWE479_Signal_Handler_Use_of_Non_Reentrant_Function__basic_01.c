/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_01.c
Label Definition File: CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 479 Signal Handler Use of Non-Reentrant Function
 * Sinks:
 *    GoodSink: Don't call a function from within the signal handler
 *    BadSink : malloc() and free() inside a signal handler
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <signal.h>

static void helperBad(int sig)
{
    /* FLAW: malloc and free are not re-entrant */
    /* Used to be printf in here, but we are trying to avoid that.
     * Detecting that printLine ultimately calls printf requires inter-
     * procedural analysis, so we cannot do that either.  So instead,
     * do something very contrived with malloc/free
     */
    void *voidPointer = malloc(10);
    if (voidPointer == NULL) {exit(-1);}
    free(voidPointer);
}

static volatile sig_atomic_t volatileSigAtomic = 0;

static void helperGood(int sig)
{
    /* FIX: Basically, "don't do anything" in signal handlers.  Set a flag at
     * best, and if you have to call a function, ensure it's a re-entrant
     * asynchronous-safe one that doesn't eat up a lot of time
     */
    volatileSigAtomic = sig;
}

#ifndef OMITBAD

void CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_01_bad()
{
    signal(SIGINT, helperBad);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    signal(SIGINT, helperGood);
}

void CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_01_good()
{
    good1();
}

#endif /* OMITGOOD */
