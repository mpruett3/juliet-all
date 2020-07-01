/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_array_new_no_init_64b.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass_array.label.xml
Template File: sources-sinks-64b.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_new_no_init_64
{

#ifndef OMITBAD

void badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    TwoIntsClass * * dataPtr = (TwoIntsClass * *)dataVoidPtr;
    /* dereference dataPtr into data */
    TwoIntsClass * data = (*dataPtr);
    /* POTENTIAL FLAW: Use data without initializing it */
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].intOne);
        printIntLine(data[i].intTwo);
    }
}

#endif /* OMITBAD */


} /* close namespace */
