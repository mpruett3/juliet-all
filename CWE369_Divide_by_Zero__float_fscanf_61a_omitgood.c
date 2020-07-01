/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_fscanf_61a.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

/* bad function declaration */
float CWE369_Divide_by_Zero__float_fscanf_61b_badSource(float data);

void CWE369_Divide_by_Zero__float_fscanf_61_bad()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    data = CWE369_Divide_by_Zero__float_fscanf_61b_badSource(data);
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        int result = (int)(100.0 / data);
        printIntLine(result);
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
    CWE369_Divide_by_Zero__float_fscanf_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif