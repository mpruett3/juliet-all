/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_54d.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_54
{

#ifndef OMITBAD

/* bad function declaration */
void badSink_e(twoIntsStruct * data);

void badSink_d(twoIntsStruct * data)
{
    badSink_e(data);
}

#endif /* OMITBAD */


} /* close namespace */