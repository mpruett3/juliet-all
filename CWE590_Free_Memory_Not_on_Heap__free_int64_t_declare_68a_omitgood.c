/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_68a.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

int64_t * CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_68_badData;
int64_t * CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_68b_badSink();

void CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_68_bad()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        int64_t dataBuffer[100];
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i] = 5LL;
            }
        }
        data = dataBuffer;
    }
    CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_68_badData = data;
    CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_68b_badSink();
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
    CWE590_Free_Memory_Not_on_Heap__free_int64_t_declare_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
