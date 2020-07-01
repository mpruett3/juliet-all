/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_int_54c.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-54c.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using free()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_int_54
{

#ifndef OMITBAD

/* bad function declaration */
void badSink_d(int * data);

void badSink_c(int * data)
{
    badSink_d(data);
}

#endif /* OMITBAD */


} /* close namespace */