/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__char_declare_memcpy_45.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static char * CWE127_Buffer_Underread__char_declare_memcpy_45_badData;
static char * CWE127_Buffer_Underread__char_declare_memcpy_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    char * data = CWE127_Buffer_Underread__char_declare_memcpy_45_badData;
    {
        char dest[100];
        memset(dest, 'C', 100-1); /* fill with 'C's */
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memcpy(dest, data, 100*sizeof(char));
        /* Ensure null termination */
        dest[100-1] = '\0';
        printLine(dest);
    }
}

void CWE127_Buffer_Underread__char_declare_memcpy_45_bad()
{
    char * data;
    char dataBuffer[100];
    memset(dataBuffer, 'A', 100-1);
    dataBuffer[100-1] = '\0';
    /* FLAW: Set data pointer to before the allocated memory buffer */
    data = dataBuffer - 8;
    CWE127_Buffer_Underread__char_declare_memcpy_45_badData = data;
    badSink();
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
    CWE127_Buffer_Underread__char_declare_memcpy_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif