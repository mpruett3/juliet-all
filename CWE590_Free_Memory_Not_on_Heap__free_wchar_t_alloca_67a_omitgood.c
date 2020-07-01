/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_67a.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_67_structType
{
    wchar_t * structFirst;
} CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_67b_badSink(CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_67_structType myStruct);

void CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_67_bad()
{
    wchar_t * data;
    CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_67_structType myStruct;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
        wmemset(dataBuffer, L'A', 100-1); /* fill with 'A's */
        dataBuffer[100-1] = L'\0'; /* null terminate */
        data = dataBuffer;
    }
    myStruct.structFirst = data;
    CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_67b_badSink(myStruct);
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
    CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
