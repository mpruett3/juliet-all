/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__HACK_05.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: HACK
 *    GoodSink: Comments show no indications of hacks
 *    BadSink : Comment contains the word HACK
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

void CWE546_Suspicious_Comment__HACK_05_bad()
{
    if(staticTrue)
    {
        /* FLAW: The following comment has the letters 'HACK' in it*/
        /* HACK: This comment has the letters 'HACK' in it, which is certainly
         * suspicious, because it could indicate this code needs to be investigated further.
         */
        printLine("Hello");
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
    CWE546_Suspicious_Comment__HACK_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif