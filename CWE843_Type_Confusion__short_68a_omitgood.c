/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__short_68a.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: short Point data to a short data type
 * GoodSource: Point data to an int data type
 * Sink:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

void * CWE843_Type_Confusion__short_68_badData;
void * CWE843_Type_Confusion__short_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE843_Type_Confusion__short_68b_badSink();

void CWE843_Type_Confusion__short_68_bad()
{
    void * data;
    /* Initialize data */
    data = NULL;
    {
        /* FLAW: Point data to a short */
        short shortBuffer = 8;
        data = &shortBuffer;
    }
    CWE843_Type_Confusion__short_68_badData = data;
    CWE843_Type_Confusion__short_68b_badSink();
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
    CWE843_Type_Confusion__short_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif