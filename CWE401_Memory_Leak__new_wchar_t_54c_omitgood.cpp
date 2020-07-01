/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_wchar_t_54c.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-54c.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_wchar_t_54
{

#ifndef OMITBAD

/* bad function declaration */
void badSink_d(wchar_t * data);

void badSink_c(wchar_t * data)
{
    badSink_d(data);
}

#endif /* OMITBAD */


} /* close namespace */
