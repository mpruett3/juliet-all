/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_wchar_t_loop_15.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: loop
 *    GoodSink: Copy a string using a loop with explicit null termination
 *    BadSink : Copy a string using a loop without explicit null termination
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE126_Buffer_Overread__CWE170_wchar_t_loop_15_bad()
{
    switch(6)
    {
    case 6:
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
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
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
    CWE126_Buffer_Overread__CWE170_wchar_t_loop_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif