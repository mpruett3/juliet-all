/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__rand_malloc_54d.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: rand Set data to result of RAND32(), which could be negative
 * GoodSource: Positive integer
 * Sink: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE194_Unexpected_Sign_Extension__rand_malloc_54e_badSink(short data);

void CWE194_Unexpected_Sign_Extension__rand_malloc_54d_badSink(short data)
{
    CWE194_Unexpected_Sign_Extension__rand_malloc_54e_badSink(data);
}

#endif /* OMITBAD */
