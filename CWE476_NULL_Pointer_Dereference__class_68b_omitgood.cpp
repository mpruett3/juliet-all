/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_68b.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sinks-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check data for NULL before attempting to print data->a
 *    BadSink : Print data->a
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE476_NULL_Pointer_Dereference__class_68
{

extern TwoIntsClass * badData;
extern TwoIntsClass * goodG2BData;
extern TwoIntsClass * goodB2GData;

#ifndef OMITBAD

void badSink()
{
    TwoIntsClass * data = badData;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data->intOne);
    /* avoid memory leak - deleting a NULL pointer is a no-op in C++ so no need to check for NULL */
    delete data;
}

#endif /* OMITBAD */


} /* close namespace */