/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_long_65b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-65b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using free()
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_long_65
{

#ifndef OMITBAD

void badSink(long * data)
{
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    free(data);
}

#endif /* OMITBAD */


} /* close namespace */