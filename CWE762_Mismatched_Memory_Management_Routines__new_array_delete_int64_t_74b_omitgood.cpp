/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_74b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using delete
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_74
{

#ifndef OMITBAD

void badSink(map<int, int64_t *> dataMap)
{
    /* copy data out of dataMap */
    int64_t * data = dataMap[2];
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}

#endif /* OMITBAD */


} /* close namespace */
