/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memmove_45.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memmove_45_badData;
static wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memmove_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    wchar_t * data = CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memmove_45_badData;
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        memmove(dest, data, wcslen(data)*sizeof(wchar_t));
        dest[50-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memmove_45_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    wmemset(data, L'A', 100-1); /* fill with L'A's */
    data[100-1] = L'\0'; /* null terminate */
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memmove_45_badData = data;
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
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memmove_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif