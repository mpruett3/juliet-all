/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__negative_memmove_61b.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sinks: memmove
 *    BadSink : Copy strings using memmove() with the length of data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

short CWE194_Unexpected_Sign_Extension__negative_memmove_61b_badSource(short data)
{
    /* FLAW: Use a negative number */
    data = -1;
    return data;
}

#endif /* OMITBAD */
