/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__char_15.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-15.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: char Point data to a char data type
 * GoodSource: Point data to an int data type
 * Sink:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE843_Type_Confusion__char_15_bad()
{
    void * data;
    /* Initialize data */
    data = NULL;
    switch(6)
    {
    case 6:
    {
        /* FLAW: Point data to a char */
        char charBuffer = 'a';
        data = &charBuffer;
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
    /* POTENTIAL FLAW: Attempt to access data as an int */
    printIntLine(*((int*)data));
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE843_Type_Confusion__char_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
