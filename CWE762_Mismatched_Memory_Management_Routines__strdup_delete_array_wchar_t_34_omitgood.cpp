/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_wchar_t_34.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array.label.xml
Template File: sources-sinks-34.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_wchar_t_34
{

typedef union
{
    wchar_t * unionFirst;
    wchar_t * unionSecond;
} unionType;

#ifndef OMITBAD

void bad()
{
    wchar_t * data;
    unionType myUnion;
    /* Initialize data*/
    data = NULL;
    {
        wchar_t myString[] = L"myString";
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = wcsdup(myString);
    }
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete [] data;
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_wchar_t_34; /* so that we can use good and bad easily */

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