/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_68a.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array.label.xml
Template File: sources-sinks-68a.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_68
{

char * badData;
char * goodG2BData;
char * goodB2GData;

#ifndef OMITBAD

/* bad function declaration */
void badSink();

void bad()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = strdup(myString);
    }
    badData = data;
    badSink();
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_68; /* so that we can use good and bad easily */

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