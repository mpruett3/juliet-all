/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_fscanf_67b.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

typedef struct _CWE369_Divide_by_Zero__float_fscanf_67_structType
{
    float structFirst;
} CWE369_Divide_by_Zero__float_fscanf_67_structType;

#ifndef OMITBAD

void CWE369_Divide_by_Zero__float_fscanf_67b_badSink(CWE369_Divide_by_Zero__float_fscanf_67_structType myStruct)
{
    float data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
}

#endif /* OMITBAD */

