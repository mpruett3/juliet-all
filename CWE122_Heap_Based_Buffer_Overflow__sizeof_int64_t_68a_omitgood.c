/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_68a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int64_t * CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_68_badData;
int64_t * CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_68b_badSink();

void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_68_bad()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
    /* FLAW: Using sizeof the pointer and not the data type in malloc() */
    data = (int64_t *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    *data = 2147483643LL;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_68_badData = data;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_68b_badSink();
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif