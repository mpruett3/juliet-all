/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__malloc_wchar_t_memmove_22b.c
Label Definition File: CWE124_Buffer_Underwrite__malloc.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE124_Buffer_Underwrite__malloc_wchar_t_memmove_22_badGlobal;

wchar_t * CWE124_Buffer_Underwrite__malloc_wchar_t_memmove_22_badSource(wchar_t * data)
{
    if(CWE124_Buffer_Underwrite__malloc_wchar_t_memmove_22_badGlobal)
    {
        {
            wchar_t * dataBuffer = (wchar_t *)malloc(100*sizeof(wchar_t));
            if (dataBuffer == NULL) {exit(-1);}
            wmemset(dataBuffer, L'A', 100-1);
            dataBuffer[100-1] = L'\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = dataBuffer - 8;
        }
    }
    return data;
}

#endif /* OMITBAD */

