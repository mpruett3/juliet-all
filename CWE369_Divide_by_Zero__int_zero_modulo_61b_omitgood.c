/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_modulo_61b.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

int CWE369_Divide_by_Zero__int_zero_modulo_61b_badSource(int data)
{
    /* POTENTIAL FLAW: Set data to zero */
    data = 0;
    return data;
}

#endif /* OMITBAD */

