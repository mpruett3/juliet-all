/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_54c.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sinks-54c.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check data for NULL before attempting to print data->a
 *    BadSink : Print data->a
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE476_NULL_Pointer_Dereference__class_54
{

#ifndef OMITBAD

/* bad function declaration */
void badSink_d(TwoIntsClass * data);

void badSink_c(TwoIntsClass * data)
{
    badSink_d(data);
}

#endif /* OMITBAD */


} /* close namespace */