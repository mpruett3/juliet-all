/*
 * @description Unused parameter variable
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static void helperBad(int intBad) 
{
    /* FLAW: Do not use the parameter variable intBad */
    printLine("This function does not use the parameter variable: intBad.");
}

void CWE563_Unused_Variable__unused_parameter_variable_01_bad() 
{
    helperBad(5);
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
    CWE563_Unused_Variable__unused_parameter_variable_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif