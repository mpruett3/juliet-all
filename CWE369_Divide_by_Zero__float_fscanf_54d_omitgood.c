/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_fscanf_54d.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_by_Zero__float_fscanf_54e_badSink(float data);

void CWE369_Divide_by_Zero__float_fscanf_54d_badSink(float data)
{
    CWE369_Divide_by_Zero__float_fscanf_54e_badSink(data);
}

#endif /* OMITBAD */

