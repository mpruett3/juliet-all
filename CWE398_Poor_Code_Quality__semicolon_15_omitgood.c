/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__semicolon_15.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: semicolon
 *    GoodSink: Removed statement that has no effect
 *    BadSink : A statement that has no effect
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE398_Poor_Code_Quality__semicolon_15_bad()
{
    switch(6)
    {
    case 6:
        /* FLAW: the statement has no effect */
        ;
        printLine("Hello from bad()");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
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
    CWE398_Poor_Code_Quality__semicolon_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif