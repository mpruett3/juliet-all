/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_realloc_16.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__int_realloc_16_bad()
{
    int * data;
    data = NULL;
    while(1)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (int *)realloc(data, 100*sizeof(int));
        if (data == NULL) {exit(-1);}
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
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
    CWE401_Memory_Leak__int_realloc_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
