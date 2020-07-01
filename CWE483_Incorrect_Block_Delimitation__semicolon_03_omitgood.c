/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE483_Incorrect_Block_Delimitation__semicolon_03.c
Label Definition File: CWE483_Incorrect_Block_Delimitation.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 483 Incorrect Block Delimitation
 * Sinks: semicolon
 *    GoodSink: Absence of suspicious semicolon
 *    BadSink : Suspicious semicolon before the if statement brace
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE483_Incorrect_Block_Delimitation__semicolon_03_bad()
{
    if(5==5)
    {
        {
            int x = (rand() % 3);
            int y = 0;
            /* FLAW: Suspicious semicolon before the if statement brace */
            if (x == 0);
            {
                printLine("x == 0");
                y = 1;
            }
            if (y)
            {
                printLine("x was 0\n");
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
    CWE483_Incorrect_Block_Delimitation__semicolon_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
