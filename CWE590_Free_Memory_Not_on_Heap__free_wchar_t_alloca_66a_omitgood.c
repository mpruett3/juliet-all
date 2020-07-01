/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_66a.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_66b_badSink(wchar_t * dataArray[]);

void CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_66_bad()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
        wmemset(dataBuffer, L'A', 100-1); /* fill with 'A's */
        dataBuffer[100-1] = L'\0'; /* null terminate */
        data = dataBuffer;
    }
    /* put data in array */
    dataArray[2] = data;
    CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_66b_badSink(dataArray);
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
    CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
