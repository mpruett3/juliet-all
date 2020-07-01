/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__LATER_01.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: LATER
 *    GoodSink: Comments show no indications that the code is unfinished
 *    BadSink : Comment contains the word LATER
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

static void good1()
{
    /* FIX: Removed the suspicious comments */
    printLine("Hello");
}

void CWE546_Suspicious_Comment__LATER_01_good()
{
    good1();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE546_Suspicious_Comment__LATER_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif