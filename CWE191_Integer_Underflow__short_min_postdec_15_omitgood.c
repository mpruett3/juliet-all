/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_min_postdec_15.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for short
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__short_min_postdec_15_bad()
{
    short data;
    data = 0;
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Use the minimum size of the data type */
        data = SHRT_MIN;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
    switch(7)
    {
    case 7:
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        short result = data;
        printIntLine(result);
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
    CWE191_Integer_Underflow__short_min_postdec_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif