/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_twointsStruct_53c.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_twointsStruct_53
{

#ifndef OMITBAD

/* bad function declaration */
void badSink_d(twoIntsStruct * data);

void badSink_c(twoIntsStruct * data)
{
    badSink_d(data);
}

#endif /* OMITBAD */


} /* close namespace */