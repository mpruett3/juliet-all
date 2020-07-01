/*
 * @description Call an empty function
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static void helperBad() 
{
    /* FLAW: Function does nothing */
}

void CWE398_Poor_Code_Quality__empty_function_01_bad() 
{
    helperBad();
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
    CWE398_Poor_Code_Quality__empty_function_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif
