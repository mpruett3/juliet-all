/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__char_malloc_22a.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
int CWE690_NULL_Deref_From_Return__char_malloc_22_badGlobal = 0;

void CWE690_NULL_Deref_From_Return__char_malloc_22_badSink(char * data);

void CWE690_NULL_Deref_From_Return__char_malloc_22_bad()
{
    char * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (char *)malloc(20*sizeof(char));
    CWE690_NULL_Deref_From_Return__char_malloc_22_badGlobal = 1; /* true */
    CWE690_NULL_Deref_From_Return__char_malloc_22_badSink(data);
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__char_malloc_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif