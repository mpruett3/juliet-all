/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_zero_22b.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-22b.tmpl.c
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
extern int CWE369_Divide_by_Zero__float_zero_22_badGlobal;

void CWE369_Divide_by_Zero__float_zero_22_badSink(float data)
{
    if(CWE369_Divide_by_Zero__float_zero_22_badGlobal)
    {
        {
            /* POTENTIAL FLAW: Possibly divide by zero */
            int result = (int)(100.0 / data);
            printIntLine(result);
        }
    }
}

#endif /* OMITBAD */

