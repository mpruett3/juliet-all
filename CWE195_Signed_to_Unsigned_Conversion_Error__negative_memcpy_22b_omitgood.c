/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_22b.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_22_badGlobal;

int CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_22_badSource(int data)
{
    if(CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_22_badGlobal)
    {
        /* FLAW: Use a negative number */
        data = -1;
    }
    return data;
}

#endif /* OMITBAD */

