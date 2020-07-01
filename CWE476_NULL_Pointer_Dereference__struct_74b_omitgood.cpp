/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__struct_74b.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace CWE476_NULL_Pointer_Dereference__struct_74
{

#ifndef OMITBAD

void badSink(map<int, twoIntsStruct *> dataMap)
{
    /* copy data out of dataMap */
    twoIntsStruct * data = dataMap[2];
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data->intOne);
}

#endif /* OMITBAD */


} /* close namespace */
