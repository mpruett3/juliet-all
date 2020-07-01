/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_rand_to_short_54d.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Less than CHAR_MAX
 * Sink: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE197_Numeric_Truncation_Error__int_rand_to_short_54e_badSink(int data);

void CWE197_Numeric_Truncation_Error__int_rand_to_short_54d_badSink(int data)
{
    CWE197_Numeric_Truncation_Error__int_rand_to_short_54e_badSink(data);
}

#endif /* OMITBAD */
