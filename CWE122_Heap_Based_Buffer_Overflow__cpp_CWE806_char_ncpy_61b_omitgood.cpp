/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_char_ncpy_61b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806.label.xml
Template File: sources-sink-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncpy
 *    BadSink : Copy data to string using strncpy
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_char_ncpy_61
{

#ifndef OMITBAD

char * badSource(char * data)
{
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    memset(data, 'A', 100-1); /* fill with 'A's */
    data[100-1] = '\0'; /* null terminate */
    return data;
}

#endif /* OMITBAD */


} /* close namespace */