/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_long_declare_32.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE590_Free_Memory_Not_on_Heap__free_long_declare_32_bad()
{
    long * data;
    long * *dataPtr1 = &data;
    long * *dataPtr2 = &data;
    data = NULL; /* Initialize data */
    {
        long * data = *dataPtr1;
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
        *dataPtr1 = data;
    }
    {
        long * data = *dataPtr2;
        printLongLine(data[0]);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        free(data);
    }
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
    CWE590_Free_Memory_Not_on_Heap__free_long_declare_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
