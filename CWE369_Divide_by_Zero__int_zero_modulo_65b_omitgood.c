/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_modulo_65b.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_by_Zero__int_zero_modulo_65b_badSink(int data)
{
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

#endif /* OMITBAD */

