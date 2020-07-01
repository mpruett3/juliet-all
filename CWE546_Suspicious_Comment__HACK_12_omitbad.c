/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__HACK_12.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: HACK
 *    GoodSink: Comments show no indications of hacks
 *    BadSink : Comment contains the word HACK
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Removed the suspicious comments */
        printLine("Hello");
    }
    else
    {
        /* FIX: Removed the suspicious comments */
        printLine("Hello");
    }
}

void CWE546_Suspicious_Comment__HACK_12_good()
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
    CWE546_Suspicious_Comment__HACK_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
