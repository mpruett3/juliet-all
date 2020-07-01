/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_long_declare_67a.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE590_Free_Memory_Not_on_Heap__free_long_declare_67_structType
{
    long * structFirst;
} CWE590_Free_Memory_Not_on_Heap__free_long_declare_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_long_declare_67b_badSink(CWE590_Free_Memory_Not_on_Heap__free_long_declare_67_structType myStruct);

void CWE590_Free_Memory_Not_on_Heap__free_long_declare_67_bad()
{
    long * data;
    CWE590_Free_Memory_Not_on_Heap__free_long_declare_67_structType myStruct;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        long dataBuffer[100];
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i] = 5L;
            }
        }
        data = dataBuffer;
    }
    myStruct.structFirst = data;
    CWE590_Free_Memory_Not_on_Heap__free_long_declare_67b_badSink(myStruct);
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
    CWE590_Free_Memory_Not_on_Heap__free_long_declare_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
