/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__empty_if_16.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: empty_if
 *    GoodSink: If statement contains code
 *    BadSink : An empty if statement has no effect
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
    {
        /* FIX: Do not include an empty if statement */
        {
            int x;
            x = (rand() % 3);
            if (x == 0)
            {
                printLine("Inside the if statement");
            }
            else
            {
                printLine("Inside the else statement");
            }
        }
        printLine("Hello from good()");
        break;
    }
}

void CWE398_Poor_Code_Quality__empty_if_16_good()
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
    CWE398_Poor_Code_Quality__empty_if_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif