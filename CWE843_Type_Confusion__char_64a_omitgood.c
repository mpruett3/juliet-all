/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__char_64a.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: char Point data to a char data type
 * GoodSource: Point data to an int data type
 * Sinks:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE843_Type_Confusion__char_64b_badSink(void * dataVoidPtr);

void CWE843_Type_Confusion__char_64_bad()
{
    void * data;
    /* Initialize data */
    data = NULL;
    {
        /* FLAW: Point data to a char */
        char charBuffer = 'a';
        data = &charBuffer;
    }
    CWE843_Type_Confusion__char_64b_badSink(&data);
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
    CWE843_Type_Confusion__char_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
