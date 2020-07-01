/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_64b.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass.label.xml
Template File: sources-sinks-64b.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource:  Don't initialize data
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_64
{

#ifndef OMITBAD

void badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    TwoIntsClass * dataPtr = (TwoIntsClass *)dataVoidPtr;
    /* dereference dataPtr into data */
    TwoIntsClass data = (*dataPtr);
    /* POTENTIAL FLAW: Use data without initializing it */
    printIntLine(data.intOne);
    printIntLine(data.intTwo);
}

#endif /* OMITBAD */


} /* close namespace */