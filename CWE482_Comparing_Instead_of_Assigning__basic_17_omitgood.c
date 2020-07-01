/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE482_Comparing_Instead_of_Assigning__basic_17.c
Label Definition File: CWE482_Comparing_Instead_of_Assigning__basic.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 482 Comparing Instead of Assigning
 * Sinks:
 *    GoodSink: Assigning
 *    BadSink : Comparing instead of assigning
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE482_Comparing_Instead_of_Assigning__basic_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            int intBadSink = 0;
            /* Print original value to avoid any unused variable incidentals */
            printIntLine(intBadSink);
            /* FLAW: meant to assign 5 to intBadSink.  Maintenance note: may generate a compiler warning, this is intentional */
            intBadSink == 5;
            printIntLine(intBadSink);
        }
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
    CWE482_Comparing_Instead_of_Assigning__basic_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
