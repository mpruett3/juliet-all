/*
 * @description Undefined Behavior - Bare Return From Function
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static int helperBad(void)
{
    /* FLAW: bare return in a function with an explicit return type of int */
    return;
}

void CWE758_Undefined_Behavior__w32_bare_return_01_bad() 
{
    int intBad = helperBad();
    printIntLine(intBad);
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
    CWE758_Undefined_Behavior__w32_bare_return_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif