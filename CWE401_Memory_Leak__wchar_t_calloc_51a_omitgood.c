/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_calloc_51a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-51a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__wchar_t_calloc_51b_badSink(wchar_t * data);

void CWE401_Memory_Leak__wchar_t_calloc_51_bad()
{
    wchar_t * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (wchar_t *)calloc(100, sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_calloc_51b_badSink(data);
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
    CWE401_Memory_Leak__wchar_t_calloc_51_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif