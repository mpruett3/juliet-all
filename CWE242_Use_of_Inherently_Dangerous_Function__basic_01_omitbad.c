/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE242_Use_of_Inherently_Dangerous_Function__basic_01.c
Label Definition File: CWE242_Use_of_Inherently_Dangerous_Function__basic.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 242 Use of Inherently Dangerous Function
 * Sinks:
 *    GoodSink: Use fgets() for bounded user input
 *    BadSink : Use gets() for user input
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#define DEST_SIZE 10


#ifndef OMITGOOD

static void good1()
{
    {
        char dest[DEST_SIZE];
        char *result;
        /* FIX: use fgets for bounded read from stdin*/
        result = fgets(dest, DEST_SIZE, stdin);
        /* Verify return value */
        if (result == NULL)
        {
            /* error condition */
            printLine("Error Condition: alter control flow to indicate action taken");
            exit(1);
        }
        dest[DEST_SIZE-1] = '\0';
        printLine(dest);
    }
}

void CWE242_Use_of_Inherently_Dangerous_Function__basic_01_good()
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
    CWE242_Use_of_Inherently_Dangerous_Function__basic_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif