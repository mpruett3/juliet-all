/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE242_Use_of_Inherently_Dangerous_Function__basic_07.c
Label Definition File: CWE242_Use_of_Inherently_Dangerous_Function__basic.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 242 Use of Inherently Dangerous Function
 * Sinks:
 *    GoodSink: Use fgets() for bounded user input
 *    BadSink : Use gets() for user input
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

#define DEST_SIZE 10

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

#ifndef OMITBAD

void CWE242_Use_of_Inherently_Dangerous_Function__basic_07_bad()
{
    if(staticFive==5)
    {
        {
            char dest[DEST_SIZE];
            char *result;
            /* FLAW: gets is inherently dangerous and cannot be used safely. */
            /* INCIDENTAL CWE120 Buffer Overflow since gets is inherently dangerous and is
             * an unbounded copy. */
            result = gets(dest);
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
    CWE242_Use_of_Inherently_Dangerous_Function__basic_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
