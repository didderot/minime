/*
 * @description Infinite Loop - do..while()
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE835_Infinite_Loop__do_01_bad() 
{
    int i = 0;
    
    /* FLAW: Infinite Loop - do..while() with no break point */
    do
    {
        printIntLine(i);
        i = (i + 1) % 256;
    } while(i >= 0);
}

#endif /* OMITBAD */


#ifndef OMITGOOD

static void good1() 
{
    int i = 0;

    do
    {
        /* FIX: Add a break point for the loop if i = 10 */
        if (i == 10) 
        { 
            break; 
        }
        printIntLine(i);
        i = (i + 1) % 256;
    } while (i >= 0);
}

void CWE835_Infinite_Loop__do_01_good() 
{
    good1();
}

#endif /* OMITGOOD */
