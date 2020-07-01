/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_negative_52a.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-52a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource: negative Negative index value
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE124_Buffer_Underwrite__CWE839_negative_52b_badSink(int data);

void CWE124_Buffer_Underwrite__CWE839_negative_52_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use an invalid index */
    data = -5;
    CWE124_Buffer_Underwrite__CWE839_negative_52b_badSink(data);
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
    CWE124_Buffer_Underwrite__CWE839_negative_52_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif