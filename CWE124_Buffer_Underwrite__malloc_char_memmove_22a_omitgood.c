/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__malloc_char_memmove_22a.c
Label Definition File: CWE124_Buffer_Underwrite__malloc.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE124_Buffer_Underwrite__malloc_char_memmove_22_badGlobal = 0;

char * CWE124_Buffer_Underwrite__malloc_char_memmove_22_badSource(char * data);

void CWE124_Buffer_Underwrite__malloc_char_memmove_22_bad()
{
    char * data;
    data = NULL;
    CWE124_Buffer_Underwrite__malloc_char_memmove_22_badGlobal = 1; /* true */
    data = CWE124_Buffer_Underwrite__malloc_char_memmove_22_badSource(data);
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        memmove(data, source, 100*sizeof(char));
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
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
    CWE124_Buffer_Underwrite__malloc_char_memmove_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
