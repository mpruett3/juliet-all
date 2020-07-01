/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__short_12.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-12.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: short Point data to a short data type
 * GoodSource: Point data to an int data type
 * Sink:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE843_Type_Confusion__short_12_bad()
{
    void * data;
    /* Initialize data */
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        {
            /* FLAW: Point data to a short */
            short shortBuffer = 8;
            data = &shortBuffer;
        }
    }
    else
    {
        {
            /* FIX: Point data to an int */
            int intBuffer = 8;
            data = &intBuffer;
        }
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
    CWE843_Type_Confusion__short_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
