/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_ncpy_68b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: ncpy
 *    BadSink : Copy string to data using wcsncpy()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_ncpy_68_badData;
extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_ncpy_68_goodG2BData;

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_ncpy_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_ncpy_68_goodG2BData;
    {
        wchar_t source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        wcsncpy(data, source, wcslen(source) + 1);
        printWLine(data);
        delete [] data;
    }
}

#endif /* OMITGOOD */

} /* close namespace */