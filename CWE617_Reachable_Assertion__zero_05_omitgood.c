/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__zero_05.c
Label Definition File: CWE617_Reachable_Assertion__zero.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * Sinks:
 *    GoodSink: assert(true), which will never trigger
 *    BadSink : assert(false), which will always trigger
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <assert.h>

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE617_Reachable_Assertion__zero_05_bad()
{
    if(staticTrue)
    {
        /* FLAW: this assertion can be reached, and will always trigger */
        assert(0); /* INCIDENTAL: CWE 571 - expression is always true - it's "true" because assert(e) basically does if (!(e)) */
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
    CWE617_Reachable_Assertion__zero_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
