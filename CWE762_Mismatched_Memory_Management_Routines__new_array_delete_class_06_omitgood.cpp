/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_class_06.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-06.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using delete
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_class_06
{

#ifndef OMITBAD

void bad()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
        data = new TwoIntsClass[100];
    }
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
         * require a call to delete [] to deallocate the memory */
        delete data;
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_class_06; /* so that we can use good and bad easily */

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
