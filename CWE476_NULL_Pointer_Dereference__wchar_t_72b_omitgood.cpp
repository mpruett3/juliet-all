/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__wchar_t_72b.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE476_NULL_Pointer_Dereference__wchar_t_72
{

#ifndef OMITBAD

void badSink(vector<wchar_t *> dataVector)
{
    /* copy data out of dataVector */
    wchar_t * data = dataVector[2];
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printWLine() checks for NULL, so we cannot use it here */
    printWcharLine(data[0]);
}

#endif /* OMITBAD */


} /* close namespace */
