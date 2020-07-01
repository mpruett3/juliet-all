/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE484_Omitted_Break_Statement_in_Switch__basic_06.c
Label Definition File: CWE484_Omitted_Break_Statement_in_Switch__basic.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 484 Omitted Break Statement in Switch
 * Sinks:
 *    GoodSink: Use breaks at the end of cases to prevent fall through
 *    BadSink : Missing break in first case
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE484_Omitted_Break_Statement_in_Switch__basic_06_bad()
{
    if(STATIC_CONST_FIVE==5)
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
    CWE484_Omitted_Break_Statement_in_Switch__basic_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
