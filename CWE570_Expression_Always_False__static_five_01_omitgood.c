/*
 * @description Expression is always false via if (false_expression)
 * 
 * */

#include "std_testcase.h"

static int staticFive = 5;

#ifndef OMITBAD

void CWE570_Expression_Always_False__static_five_01_bad() 
{
    /* FLAW: This expression is always false */
    if (staticFive != 5) 
    {
        printLine("Never prints");
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
    CWE570_Expression_Always_False__static_five_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif
