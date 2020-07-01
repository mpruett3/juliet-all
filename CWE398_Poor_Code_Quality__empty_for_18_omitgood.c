/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__empty_for_18.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: empty_for
 *    GoodSink: For statement contains code
 *    BadSink : An empty for statement has no effect
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE398_Poor_Code_Quality__empty_for_18_bad()
{
    goto sink;
sink:
    /* FLAW: An empty for statement has no effect */
    {
        int i;
        for (i = 0; i < 10; i++)
        {
        }
    }
    printLine("Hello from bad()");
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__empty_for_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif