/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_wchar_t_memcpy_68a.c
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

wchar_t * CWE127_Buffer_Underread__malloc_wchar_t_memcpy_68_badData;
wchar_t * CWE127_Buffer_Underread__malloc_wchar_t_memcpy_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE127_Buffer_Underread__malloc_wchar_t_memcpy_68b_badSink();

void CWE127_Buffer_Underread__malloc_wchar_t_memcpy_68_bad()
{
    wchar_t * data;
    data = NULL;
    {
        wchar_t * dataBuffer = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (dataBuffer == NULL) {exit(-1);}
        wmemset(dataBuffer, L'A', 100-1);
        dataBuffer[100-1] = L'\0';
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = dataBuffer - 8;
    }
    CWE127_Buffer_Underread__malloc_wchar_t_memcpy_68_badData = data;
    CWE127_Buffer_Underread__malloc_wchar_t_memcpy_68b_badSink();
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
    CWE127_Buffer_Underread__malloc_wchar_t_memcpy_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif