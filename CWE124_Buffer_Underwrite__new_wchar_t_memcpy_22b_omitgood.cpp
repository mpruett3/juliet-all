/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__new_wchar_t_memcpy_22b.cpp
Label Definition File: CWE124_Buffer_Underwrite__new.label.xml
Template File: sources-sink-22b.tmpl.cpp
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memcpy
 *    BadSink : Copy string to data using memcpy
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE124_Buffer_Underwrite__new_wchar_t_memcpy_22
{

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
extern int badGlobal;

wchar_t * badSource(wchar_t * data)
{
    if(badGlobal)
    {
        {
            wchar_t * dataBuffer = new wchar_t[100];
            wmemset(dataBuffer, L'A', 100-1);
            dataBuffer[100-1] = L'\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = dataBuffer - 8;
        }
    }
    return data;
}

#endif /* OMITBAD */


} /* close namespace */
