/*
 * @description Incorrect Block Delimitation
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE483_Incorrect_Block_Delimitation__if_without_braces_multiple_lines_01_bad()
{ 
    int x,y;

    x = (rand() % 3);
    y = 0;
    
    /* FLAW: forgot to put these two statements within braces
     * (separate lines, but indentation hints at programmer's intent) */
    if (x == 0)
        printLine("x == 0");
        y = 1;
        
    if (y)
    {
        printLine("x was 0\n");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    int x,y;
    
    x = (rand() % 3);
    y = 0;
    
    /* FIX: put the related statements within braces */
    if (x == 0)
    {
        printLine("x == 0");
        y = 1;
    }
    
    if (y) 
    {
        printLine("x was 0\n");
    }
}

void CWE483_Incorrect_Block_Delimitation__if_without_braces_multiple_lines_01_good()
{
    good1();
}

#endif /* OMITGOOD */
