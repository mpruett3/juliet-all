/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_zero_34.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <math.h>

typedef union
{
    float unionFirst;
    float unionSecond;
} CWE369_Divide_by_Zero__float_zero_34_unionType;

#ifndef OMITBAD

void CWE369_Divide_by_Zero__float_zero_34_bad()
{
    float data;
    CWE369_Divide_by_Zero__float_zero_34_unionType myUnion;
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0.0F;
    myUnion.unionFirst = data;
    {
        float data = myUnion.unionSecond;
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
    CWE369_Divide_by_Zero__float_zero_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
