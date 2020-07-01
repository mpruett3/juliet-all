/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_min_sub_45.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for int64_t
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static int64_t CWE191_Integer_Underflow__int64_t_min_sub_45_badData;
static int64_t CWE191_Integer_Underflow__int64_t_min_sub_45_goodG2BData;
static int64_t CWE191_Integer_Underflow__int64_t_min_sub_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    int64_t data = CWE191_Integer_Underflow__int64_t_min_sub_45_badData;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        int64_t result = data - 1;
        printLongLongLine(result);
    }
}

void CWE191_Integer_Underflow__int64_t_min_sub_45_bad()
{
    int64_t data;
    data = 0LL;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = LLONG_MIN;
    CWE191_Integer_Underflow__int64_t_min_sub_45_badData = data;
    badSink();
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
    CWE191_Integer_Underflow__int64_t_min_sub_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif