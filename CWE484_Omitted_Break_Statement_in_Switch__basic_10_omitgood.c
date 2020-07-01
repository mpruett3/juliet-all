/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE484_Omitted_Break_Statement_in_Switch__basic_10.c
Label Definition File: CWE484_Omitted_Break_Statement_in_Switch__basic.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 484 Omitted Break Statement in Switch
 * Sinks:
 *    GoodSink: Use breaks at the end of cases to prevent fall through
 *    BadSink : Missing break in first case
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE484_Omitted_Break_Statement_in_Switch__basic_10_bad()
{
    if(globalTrue)
    {
        {
            int x = (rand() % 3);
            /* FLAW: Missing break in first case */
            switch (x)
            {
            case 0:
                printLine("0");
            case 1:
                printLine("1");
                break;
            case 2:
                printLine("2");
                break;
            default:
                printLine("Invalid Number");
                break;
            }
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
    CWE484_Omitted_Break_Statement_in_Switch__basic_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
