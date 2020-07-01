/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_81a.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using delete
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_81.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_81
{

#ifndef OMITBAD

void bad()
{
    int64_t * data;
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new int64_t[100];
    const CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_81_base& o = CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_81_bad();
    o.action(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_int64_t_81; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif