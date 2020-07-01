/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_wchar_t_memcpy_61b.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sinks: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

wchar_t * CWE126_Buffer_Overread__malloc_wchar_t_memcpy_61b_badSource(wchar_t * data)
{
    /* FLAW: Use a small buffer */
    data = (wchar_t *)malloc(50*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    wmemset(data, L'A', 50-1); /* fill with 'A's */
    data[50-1] = L'\0'; /* null terminate */
    return data;
}

#endif /* OMITBAD */
