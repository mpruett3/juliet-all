/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_68a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

long * CWE415_Double_Free__malloc_free_long_68_badData;
long * CWE415_Double_Free__malloc_free_long_68_goodG2BData;
long * CWE415_Double_Free__malloc_free_long_68_goodB2GData;

#ifndef OMITBAD

/* bad function declaration */
void CWE415_Double_Free__malloc_free_long_68b_badSink();

void CWE415_Double_Free__malloc_free_long_68_bad()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    CWE415_Double_Free__malloc_free_long_68_badData = data;
    CWE415_Double_Free__malloc_free_long_68b_badSink();
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
    CWE415_Double_Free__malloc_free_long_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif