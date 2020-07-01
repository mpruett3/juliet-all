/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_22b.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Positive integer
 * Sink: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_22_badGlobal;

int CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_22_badSource(int data)
{
    if(CWE195_Signed_to_Unsigned_Conversion_Error__rand_strncpy_22_badGlobal)
    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }
    return data;
}

#endif /* OMITBAD */

