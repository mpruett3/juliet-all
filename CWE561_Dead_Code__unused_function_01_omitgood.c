/*
 * @description Unused function declaration
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* FLAW: this function is never used (this should be easy for a tool to determine
 * because it is statically scoped and therefore cannot be accessed outside of this source file */
static void helperBad() 
{
    printLine("helperBad()");
}

void CWE561_Dead_Code__unused_function_01_bad() 
{
    printLine("CWE561_Dead_Code__unused_function_01_bad()");
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
    CWE561_Dead_Code__unused_function_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif
