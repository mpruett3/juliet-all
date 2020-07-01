/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_zero_22a.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
int CWE369_Divide_by_Zero__float_zero_22_badGlobal = 0;

void CWE369_Divide_by_Zero__float_zero_22_badSink(float data);

void CWE369_Divide_by_Zero__float_zero_22_bad()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0.0F;
    CWE369_Divide_by_Zero__float_zero_22_badGlobal = 1; /* true */
    CWE369_Divide_by_Zero__float_zero_22_badSink(data);
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
    CWE369_Divide_by_Zero__float_zero_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
