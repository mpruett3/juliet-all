/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_rand_22b.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: rand Set data to result of RAND32(), which could be negative
 * GoodSource: Less than CHAR_MAX
 * Sink:
 *    BadSink : Convert data to a char
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE197_Numeric_Truncation_Error__short_rand_22_badGlobal;

short CWE197_Numeric_Truncation_Error__short_rand_22_badSource(short data)
{
    if(CWE197_Numeric_Truncation_Error__short_rand_22_badGlobal)
    {
        /* FLAW: Use a random number */
        data = (short)RAND32();
    }
    return data;
}

#endif /* OMITBAD */

