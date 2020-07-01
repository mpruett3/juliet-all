/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__sqrt_18.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: sqrt
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if sqrt() failed
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#include <math.h>

#ifndef OMITBAD

void CWE391_Unchecked_Error_Condition__sqrt_18_bad()
{
    goto sink;
sink:
    {
        double doubleNumber;
        doubleNumber = (double)sqrt((double)-1);
        /* FLAW: Do not check to see if sqrt() failed */
        printDoubleLine(doubleNumber);
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
    CWE391_Unchecked_Error_Condition__sqrt_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif