/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_15.c
Label Definition File: CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 688 Function Call With Incorrect Variable or Reference as Argument
 * Sinks:
 *    GoodSink: Use the correct format to print a string
 *    BadSink : Use a string format to print an int
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#define DEST_SIZE 100

#ifndef OMITBAD

void CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_15_bad()
{
    switch(6)
    {
    case 6:
    {
        char dest[DEST_SIZE];
        int intFive = 5;
        /* FLAW: int argument passed, expecting string argument */
        sprintf(dest, "%s", intFive);
        printLine(dest);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
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
    CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument__basic_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif