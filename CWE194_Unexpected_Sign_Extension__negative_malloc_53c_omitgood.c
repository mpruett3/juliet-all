/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__negative_malloc_53c.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sink: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE194_Unexpected_Sign_Extension__negative_malloc_53d_badSink(short data);

void CWE194_Unexpected_Sign_Extension__negative_malloc_53c_badSink(short data)
{
    CWE194_Unexpected_Sign_Extension__negative_malloc_53d_badSink(data);
}

#endif /* OMITBAD */
