/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_rand_65a.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of RAND32(), which may be zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_by_Zero__float_rand_65b_badSink(float data);

void CWE369_Divide_by_Zero__float_rand_65_bad()
{
    float data;
    /* define a function pointer */
    void (*funcPtr) (float) = CWE369_Divide_by_Zero__float_rand_65b_badSink;
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
    data = (float)RAND32();
    /* use the function pointer */
    funcPtr(data);
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
    CWE369_Divide_by_Zero__float_rand_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif