/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_wchar_t_68b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using delete
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_wchar_t_68
{

extern wchar_t * badData;
extern wchar_t * goodG2BData;
extern wchar_t * goodB2GData;

#ifndef OMITBAD

void badSink()
{
    wchar_t * data = badData;
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}

#endif /* OMITBAD */


} /* close namespace */
