/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_wchar_t_strncpy_03.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: strncpy
 *    GoodSink: Copy a string using wcsncpy() with explicit null termination
 *    BadSink : Copy a string using wcsncpy() without explicit null termination
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE126_Buffer_Overread__CWE170_wchar_t_strncpy_03_bad()
{
    if(5==5)
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            /* wcsncpy() does not null terminate if the string in the src buffer is larger than
             * the number of characters being copied to the dest buffer */
            wcsncpy(dest, data, 99);
            /* FLAW: do not explicitly null terminate dest after the use of wcsncpy() */
            printWLine(dest);
        }
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE126_Buffer_Overread__CWE170_wchar_t_strncpy_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
