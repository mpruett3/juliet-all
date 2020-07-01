/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__negative_memcpy_22b.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
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
extern int CWE194_Unexpected_Sign_Extension__negative_memcpy_22_badGlobal;

short CWE194_Unexpected_Sign_Extension__negative_memcpy_22_badSource(short data)
{
    if(CWE194_Unexpected_Sign_Extension__negative_memcpy_22_badGlobal)
    {
        /* FLAW: Use a negative number */
        data = -1;
    }
    return data;
}

#endif /* OMITBAD */

