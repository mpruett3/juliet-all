/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__wchar_t_alloca_cpy_09.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-09.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: cpy
 *    BadSink : Copy string to data using wcscpy
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE124_Buffer_Underwrite__wchar_t_alloca_cpy_09_bad()
{
    wchar_t * data;
    wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataBuffer, L'A', 100-1);
    dataBuffer[100-1] = L'\0';
    if(GLOBAL_CONST_TRUE)
    {
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = dataBuffer - 8;
    }
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with 'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        wcscpy(data, source);
        printWLine(data);
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
    CWE124_Buffer_Underwrite__wchar_t_alloca_cpy_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif