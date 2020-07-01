/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_rand_68b.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of RAND32(), which may be zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

extern float CWE369_Divide_by_Zero__float_rand_68_badData;
extern float CWE369_Divide_by_Zero__float_rand_68_goodG2BData;
extern float CWE369_Divide_by_Zero__float_rand_68_goodB2GData;

#ifndef OMITBAD

void CWE369_Divide_by_Zero__float_rand_68b_badSink()
{
    float data = CWE369_Divide_by_Zero__float_rand_68_badData;
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
}

#endif /* OMITBAD */

