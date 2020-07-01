/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE843_Type_Confusion__short_17.c
Label Definition File: CWE843_Type_Confusion.label.xml
Template File: sources-sink-17.tmpl.c
*/
/*
 * @description
 * CWE: 843 Type Confusion
 * BadSource: short Point data to a short data type
 * GoodSource: Point data to an int data type
 * Sink:
 *    BadSink : Attempt to access data as an int
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the for statements */
static void goodG2B()
{
    int h;
    void * data;
    /* Initialize data */
    data = NULL;
    for(h = 0; h < 1; h++)
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

void CWE843_Type_Confusion__short_17_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

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
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE843_Type_Confusion__short_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
