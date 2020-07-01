/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_char_memcpy_07.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-07.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sink: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The variable below is not declared "const", but is never assigned
 * any other value so a tool should be able to identify that reads of
 * this will always give its initialized value.
 */
static int staticFive = 5;

#ifndef OMITBAD

void CWE126_Buffer_Overread__malloc_char_memcpy_07_bad()
{
    char * data;
    data = NULL;
    if(staticFive==5)
    {
        /* FLAW: Use a small buffer */
        data = (char *)malloc(50*sizeof(char));
        if (data == NULL) {exit(-1);}
        memset(data, 'A', 50-1); /* fill with 'A's */
        data[50-1] = '\0'; /* null terminate */
    }
    {
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, strlen(dest)*sizeof(char));
        dest[100-1] = '\0';
        printLine(dest);
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
    CWE126_Buffer_Overread__malloc_char_memcpy_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
