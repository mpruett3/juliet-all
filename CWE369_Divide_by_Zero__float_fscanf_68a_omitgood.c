/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_fscanf_68a.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

float CWE369_Divide_by_Zero__float_fscanf_68_badData;
float CWE369_Divide_by_Zero__float_fscanf_68_goodG2BData;
float CWE369_Divide_by_Zero__float_fscanf_68_goodB2GData;

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_by_Zero__float_fscanf_68b_badSink();

void CWE369_Divide_by_Zero__float_fscanf_68_bad()
{
    float data;
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Use a value input from the console using fscanf() */
    fscanf (stdin, "%f", &data);
    CWE369_Divide_by_Zero__float_fscanf_68_badData = data;
    CWE369_Divide_by_Zero__float_fscanf_68b_badSink();
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
    CWE369_Divide_by_Zero__float_fscanf_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif