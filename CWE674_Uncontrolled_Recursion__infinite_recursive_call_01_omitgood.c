/*
 * @description Uncontrolled Recursion
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static void helperBad()
{
    /* FLAW: this function causes infinite recursion */
    helperBad(); /* maintenance note: this may generate a warning, this is on purpose */
}

void CWE674_Uncontrolled_Recursion__infinite_recursive_call_01_bad()
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
    CWE674_Uncontrolled_Recursion__infinite_recursive_call_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
