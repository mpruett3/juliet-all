/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_malloc_44.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-44.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_malloc_44
{

#ifndef OMITBAD

static void badSink(int64_t * data)
{
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete data;
}

void bad()
{
    int64_t * data;
    /* define a function pointer */
    void (*funcPtr) (int64_t *) = badSink;
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_malloc_44; /* so that we can use good and bad easily */

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