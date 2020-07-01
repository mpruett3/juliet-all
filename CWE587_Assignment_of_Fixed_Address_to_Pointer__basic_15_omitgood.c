/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_15.c
Label Definition File: CWE587_Assignment_of_Fixed_Address_to_Pointer__basic.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 587 Assignment of Fixed Address to Pointer
 * Sinks:
 *    GoodSink: Assign the pointer to a stack variable
 *    BadSink : Assign fixed address to pointer
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_15_bad()
{
    switch(6)
    {
    case 6:
    {
        /* FLAW: Assigning fixed address to pointer */
        char *charPointer = (char*)0x400000;
        printHexCharLine(*charPointer);
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
    CWE587_Assignment_of_Fixed_Address_to_Pointer__basic_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
