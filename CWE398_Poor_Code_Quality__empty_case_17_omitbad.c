/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__empty_case_17.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: empty_case
 *    GoodSink: Case statement contains code
 *    BadSink : An empty case statement has no effect
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        /* FIX: Do not include an empty case statement */
        {
            int x = (rand() % 3);
            switch (x)
            {
            case 0:
                printLine("Inside the case statement");
                break;
            }
        }
        printLine("Hello from good()");
    }
}

void CWE398_Poor_Code_Quality__empty_case_17_good()
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
    CWE398_Poor_Code_Quality__empty_case_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
