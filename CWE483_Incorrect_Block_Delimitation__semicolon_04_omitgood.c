/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE483_Incorrect_Block_Delimitation__semicolon_04.c
Label Definition File: CWE483_Incorrect_Block_Delimitation.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 483 Incorrect Block Delimitation
 * Sinks: semicolon
 *    GoodSink: Absence of suspicious semicolon
 *    BadSink : Suspicious semicolon before the if statement brace
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE483_Incorrect_Block_Delimitation__semicolon_04_bad()
{
    if(STATIC_CONST_TRUE)
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
    CWE483_Incorrect_Block_Delimitation__semicolon_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
