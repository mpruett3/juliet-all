/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_calloc_68a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

int * CWE401_Memory_Leak__int_calloc_68_badData;
int * CWE401_Memory_Leak__int_calloc_68_goodG2BData;
int * CWE401_Memory_Leak__int_calloc_68_goodB2GData;

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__int_calloc_68b_badSink();

void CWE401_Memory_Leak__int_calloc_68_bad()
{
    int * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (int *)calloc(100, sizeof(int));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
    CWE401_Memory_Leak__int_calloc_68_badData = data;
    CWE401_Memory_Leak__int_calloc_68b_badSink();
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
    CWE401_Memory_Leak__int_calloc_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif