/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_rand_53a.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-53a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of RAND32(), which may be zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__float_rand_53b_goodG2BSink(float data);

static void goodG2B()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    /* FIX: Use a hardcoded number that won't a divide by zero */
    data = 2.0F;
    CWE369_Divide_by_Zero__float_rand_53b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__float_rand_53b_goodB2GSink(float data);

static void goodB2G()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
    data = (float)RAND32();
    CWE369_Divide_by_Zero__float_rand_53b_goodB2GSink(data);
}

void CWE369_Divide_by_Zero__float_rand_53_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE369_Divide_by_Zero__float_rand_53_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif