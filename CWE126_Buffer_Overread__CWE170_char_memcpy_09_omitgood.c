/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_char_memcpy_09.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: memcpy
 *    GoodSink: Copy a string using memcpy with explicit null termination
 *    BadSink : Copy a string using memcpy without explicit null termination
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE126_Buffer_Overread__CWE170_char_memcpy_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            char data[150], dest[100];
            /* Initialize data */
            memset(data, 'A', 149);
            data[149] = '\0';
            memcpy(dest, data, 99*sizeof(char));
            /* FLAW: do not explicitly null terminate dest after the use of memcpy */
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
    CWE126_Buffer_Overread__CWE170_char_memcpy_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif