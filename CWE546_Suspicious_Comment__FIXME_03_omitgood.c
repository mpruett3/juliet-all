/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__FIXME_03.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: FIXME
 *    GoodSink: Comments show no indications of broken code
 *    BadSink : Comment contains the word FIXME
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE546_Suspicious_Comment__FIXME_03_bad()
{
    if(5==5)
    {
        /* FLAW: The following comment has the letters 'FIXME' in it*/
        /* FIXME: This comment has the letters 'FIXME' in it, which is certainly
         * suspicious, because it could indicate this code needs to be fixed.
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
    CWE546_Suspicious_Comment__FIXME_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
