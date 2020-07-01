/*
 * @description Infinite Loop - for()
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE835_Infinite_Loop__for_empty_01_bad() 
{
    int i = 0;
    
    /* FLAW: Infinite Loop - for() with no break point */
    for(;;)
    {
        printIntLine(i);
        i++;
    }
}

#endif /* OMITBAD */



/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[]) 
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );


#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE835_Infinite_Loop__for_empty_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif
