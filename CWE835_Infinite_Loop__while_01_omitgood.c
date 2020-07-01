/*
 * @description Infinite Loop - while()
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE835_Infinite_Loop__while_01_bad() 
{
    int i = 0;
    
    /* FLAW: Infinite Loop - while() with no break point */
    while(i >= 0)
    {
        printIntLine(i);
        i = (i + 1) % 256;
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
    CWE835_Infinite_Loop__while_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif
