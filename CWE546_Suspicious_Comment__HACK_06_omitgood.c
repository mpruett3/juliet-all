/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__HACK_06.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: HACK
 *    GoodSink: Comments show no indications of hacks
 *    BadSink : Comment contains the word HACK
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE546_Suspicious_Comment__HACK_06_bad()
{
    if(STATIC_CONST_FIVE==5)
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
    CWE546_Suspicious_Comment__HACK_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif