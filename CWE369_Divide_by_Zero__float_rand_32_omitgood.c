/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_rand_32.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of RAND32(), which may be zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

void CWE369_Divide_by_Zero__float_rand_32_bad()
{
    float data;
    float *dataPtr1 = &data;
    float *dataPtr2 = &data;
    /* Initialize data */
    data = 0.0F;
    {
        float data = *dataPtr1;
        /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
        data = (float)RAND32();
        *dataPtr1 = data;
    }
    {
        float data = *dataPtr2;
        {
            /* POTENTIAL FLAW: Possibly divide by zero */
            int result = (int)(100.0 / data);
            printIntLine(result);
        }
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
    CWE369_Divide_by_Zero__float_rand_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
