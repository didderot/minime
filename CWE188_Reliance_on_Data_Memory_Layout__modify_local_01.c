/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE188_Reliance_on_Data_Memory_Layout__modify_local_01.c
Label Definition File: CWE188_Reliance_on_Data_Memory_Layout.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 188 Reliance on Data Memory Layout
 * Sinks: modify_local
 *    GoodSink: Modify the second field of the struct using the field name
 *    BadSink : Attempt to modify second field in struct, assuming the first field is an int
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE188_Reliance_on_Data_Memory_Layout__modify_local_01_bad()
{
    {
        struct
        {
            char charFirst;
            int intSecond;
        } structCharInt;
        char *charPtr;
        structCharInt.charFirst = 1;
        charPtr = &structCharInt.charFirst;
        /* FLAW: Attempt to modify intSecond assuming intSecond comes after charFirst and
         * is aligned on an int-boundary after charFirst */
        *(int*)(charPtr + sizeof(int)) = 5;
        printIntLine(structCharInt.charFirst);
        printIntLine(structCharInt.intSecond);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        struct
        {
            char charFirst;
            int intSecond;
        } structCharInt;
        structCharInt.charFirst = 1;
        /* FIX: Do not make unwarranted assumptions about underlying data model
         * Modify and access data appropriately */
        structCharInt.intSecond = 5;
        printIntLine(structCharInt.charFirst);
        printIntLine(structCharInt.intSecond);
    }
}

void CWE188_Reliance_on_Data_Memory_Layout__modify_local_01_good()
{
    good1();
}

#endif /* OMITGOOD */
