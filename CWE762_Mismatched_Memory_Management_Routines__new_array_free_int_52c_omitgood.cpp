/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_int_52c.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-52c.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using free()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_int_52
{

#ifndef OMITBAD

void badSink_c(int * data)
{
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    free(data);
}

#endif /* OMITBAD */


} /* close namespace */