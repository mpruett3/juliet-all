/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_char_loop_10.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: loop
 *    GoodSink: Copy a string using a loop with explicit null termination
 *    BadSink : Copy a string using a loop without explicit null termination
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE126_Buffer_Overread__CWE170_char_loop_10_bad()
{
    if(globalTrue)
    {
        {
            char src[150], dest[100];
            int i;
            /* Initialize src */
            memset(src, 'A', 149);
            src[149] = '\0';
            for(i=0; i < 99; i++)
            {
                dest[i] = src[i];
            }
            /* FLAW: do not explicitly null terminate dest after the loop */
            printLine(dest);
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
    CWE126_Buffer_Overread__CWE170_char_loop_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
