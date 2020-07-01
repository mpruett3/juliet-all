/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_large_22b.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than CHAR_MAX
 * GoodSource: Less than CHAR_MAX
 * Sink:
 *    BadSink : Convert data to a char
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE197_Numeric_Truncation_Error__short_large_22_badGlobal;

short CWE197_Numeric_Truncation_Error__short_large_22_badSource(short data)
{
    if(CWE197_Numeric_Truncation_Error__short_large_22_badGlobal)
    {
        /* FLAW: Use a number larger than CHAR_MAX */
        data = CHAR_MAX + 1;
    }
    return data;
}

#endif /* OMITBAD */

