/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__wchar_t_alloca_cpy_06.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-06.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: cpy
 *    BadSink : Copy data to string using wcscpy
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The variable below is declared "const", so a tool should be able
 * to identify that reads of this will always give its initialized value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE127_Buffer_Underread__wchar_t_alloca_cpy_06_bad()
{
    wchar_t * data;
    wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataBuffer, L'A', 100-1);
    dataBuffer[100-1] = L'\0';
    if(STATIC_CONST_FIVE==5)
    {
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = dataBuffer - 8;
    }
    {
        wchar_t dest[100*2];
        wmemset(dest, L'C', 100*2-1); /* fill with 'C's */
        dest[100*2-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        wcscpy(dest, data);
        printWLine(dest);
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
    CWE127_Buffer_Underread__wchar_t_alloca_cpy_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif