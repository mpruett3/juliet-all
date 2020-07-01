/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_declare_memcpy_54b.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sink: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE126_Buffer_Overread__wchar_t_declare_memcpy_54c_badSink(wchar_t * data);

void CWE126_Buffer_Overread__wchar_t_declare_memcpy_54b_badSink(wchar_t * data)
{
    CWE126_Buffer_Overread__wchar_t_declare_memcpy_54c_badSink(data);
}

#endif /* OMITBAD */
