/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_char_declare_68a.c
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

char * CWE590_Free_Memory_Not_on_Heap__free_char_declare_68_badData;
char * CWE590_Free_Memory_Not_on_Heap__free_char_declare_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE590_Free_Memory_Not_on_Heap__free_char_declare_68b_badSink();

void CWE590_Free_Memory_Not_on_Heap__free_char_declare_68_bad()
{
    char * data;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        char dataBuffer[100];
        memset(dataBuffer, 'A', 100-1); /* fill with 'A's */
        dataBuffer[100-1] = '\0'; /* null terminate */
        data = dataBuffer;
    }
    CWE590_Free_Memory_Not_on_Heap__free_char_declare_68_badData = data;
    CWE590_Free_Memory_Not_on_Heap__free_char_declare_68b_badSink();
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
    CWE590_Free_Memory_Not_on_Heap__free_char_declare_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
