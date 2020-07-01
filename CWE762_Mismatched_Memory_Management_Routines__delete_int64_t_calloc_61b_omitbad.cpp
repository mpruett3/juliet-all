/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_calloc_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_calloc_61
{


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int64_t * goodG2BSource(int64_t * data)
{
    /* FIX: Allocate memory from the heap using new */
    data = new int64_t;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
int64_t * goodB2GSource(int64_t * data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (int64_t *)calloc(100, sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    return data;
}

#endif /* OMITGOOD */

} /* close namespace */