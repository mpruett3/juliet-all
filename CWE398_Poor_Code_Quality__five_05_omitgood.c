/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__five_05.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: five
 *    GoodSink: Removed statement that has no effect
 *    BadSink : A statement that has no effect
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE398_Poor_Code_Quality__five_05_bad()
{
    if(staticTrue)
    {
        /* FLAW: the statement has no effect */
        5;
        printLine("Hello from bad()");
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
    CWE398_Poor_Code_Quality__five_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
