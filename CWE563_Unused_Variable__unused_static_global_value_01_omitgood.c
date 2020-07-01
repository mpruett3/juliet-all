/*
 * @description Unused static global value
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static int staticGlobalBad = 0;

void CWE563_Unused_Variable__unused_static_global_value_01_bad() 
{
    /* FLAW: Overwrite the initial value of the static global variable before use */
    staticGlobalBad = 10;
    printIntLine(staticGlobalBad);
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
    CWE563_Unused_Variable__unused_static_global_value_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif