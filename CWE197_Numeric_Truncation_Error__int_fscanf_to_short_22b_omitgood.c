/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fscanf_to_short_22b.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sink: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE197_Numeric_Truncation_Error__int_fscanf_to_short_22_badGlobal;

int CWE197_Numeric_Truncation_Error__int_fscanf_to_short_22_badSource(int data)
{
    if(CWE197_Numeric_Truncation_Error__int_fscanf_to_short_22_badGlobal)
    {
        /* POTENTIAL FLAW: Read data from the console using fscanf() */
        fscanf(stdin, "%d", &data);
    }
    return data;
}

#endif /* OMITBAD */
