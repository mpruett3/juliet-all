/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_large_to_char_22b.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than SHRT_MAX
 * GoodSource: Less than CHAR_MAX
 * Sink: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE197_Numeric_Truncation_Error__int_large_to_char_22_badGlobal;

int CWE197_Numeric_Truncation_Error__int_large_to_char_22_badSource(int data)
{
    if(CWE197_Numeric_Truncation_Error__int_large_to_char_22_badGlobal)
    {
        /* FLAW: Use a number larger than SHRT_MAX */
        data = SHRT_MAX + 5;
    }
    return data;
}

#endif /* OMITBAD */
