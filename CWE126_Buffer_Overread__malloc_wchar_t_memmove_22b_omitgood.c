/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_wchar_t_memmove_22b.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sink: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE126_Buffer_Overread__malloc_wchar_t_memmove_22_badGlobal;

wchar_t * CWE126_Buffer_Overread__malloc_wchar_t_memmove_22_badSource(wchar_t * data)
{
    if(CWE126_Buffer_Overread__malloc_wchar_t_memmove_22_badGlobal)
    {
        /* FLAW: Use a small buffer */
        data = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        wmemset(data, L'A', 50-1); /* fill with 'A's */
        data[50-1] = L'\0'; /* null terminate */
    }
    return data;
}

#endif /* OMITBAD */

