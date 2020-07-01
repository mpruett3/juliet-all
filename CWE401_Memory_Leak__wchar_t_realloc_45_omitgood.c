/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_realloc_45.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static wchar_t * CWE401_Memory_Leak__wchar_t_realloc_45_badData;
static wchar_t * CWE401_Memory_Leak__wchar_t_realloc_45_goodG2BData;
static wchar_t * CWE401_Memory_Leak__wchar_t_realloc_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    wchar_t * data = CWE401_Memory_Leak__wchar_t_realloc_45_badData;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

void CWE401_Memory_Leak__wchar_t_realloc_45_bad()
{
    wchar_t * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (wchar_t *)realloc(data, 100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_realloc_45_badData = data;
    badSink();
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
    CWE401_Memory_Leak__wchar_t_realloc_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
