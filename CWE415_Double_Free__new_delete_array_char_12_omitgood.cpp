/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_char_12.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_char_12
{

#ifndef OMITBAD

void bad()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = new char[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
    }
    else
    {
        data = new char[100];
        /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    }
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
    else
    {
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__new_delete_array_char_12; /* so that we can use good and bad easily */

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