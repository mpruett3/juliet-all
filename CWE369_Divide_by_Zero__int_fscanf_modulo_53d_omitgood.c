/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_fscanf_modulo_53d.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-53d.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_by_Zero__int_fscanf_modulo_53d_badSink(int data)
{
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

#endif /* OMITBAD */

