/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_wchar_t_loop_17.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: loop
 *    GoodSink: Copy a string using a loop with explicit null termination
 *    BadSink : Copy a string using a loop without explicit null termination
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE126_Buffer_Overread__CWE170_wchar_t_loop_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            wchar_t src[150], dest[100];
            int i;
            /* Initialize src */
            wmemset(src, L'A', 149);
            src[149] = L'\0';
            for(i=0; i < 99; i++)
            {
                dest[i] = src[i];
            }
            /* FLAW: do not explicitly null terminate dest after the loop */
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
    CWE126_Buffer_Overread__CWE170_wchar_t_loop_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif