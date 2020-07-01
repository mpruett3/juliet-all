/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_fscanf_divide_68b.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sinks: divide
 *    GoodSink: Check for zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE369_Divide_by_Zero__int_fscanf_divide_68_badData;
extern int CWE369_Divide_by_Zero__int_fscanf_divide_68_goodG2BData;
extern int CWE369_Divide_by_Zero__int_fscanf_divide_68_goodB2GData;

#ifndef OMITBAD

void CWE369_Divide_by_Zero__int_fscanf_divide_68b_badSink()
{
    int data = CWE369_Divide_by_Zero__int_fscanf_divide_68_badData;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

#endif /* OMITBAD */

