/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_72b.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check data for NULL before attempting to print data->a
 *    BadSink : Print data->a
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE476_NULL_Pointer_Dereference__class_72
{

#ifndef OMITBAD

void badSink(vector<TwoIntsClass *> dataVector)
{
    /* copy data out of dataVector */
    TwoIntsClass * data = dataVector[2];
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data->intOne);
    /* avoid memory leak - deleting a NULL pointer is a no-op in C++ so no need to check for NULL */
    delete data;
}

#endif /* OMITBAD */


} /* close namespace */
