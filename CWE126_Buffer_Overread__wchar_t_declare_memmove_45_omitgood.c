/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_declare_memmove_45.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static wchar_t * CWE126_Buffer_Overread__wchar_t_declare_memmove_45_badData;
static wchar_t * CWE126_Buffer_Overread__wchar_t_declare_memmove_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    wchar_t * data = CWE126_Buffer_Overread__wchar_t_declare_memmove_45_badData;
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: using memmove with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memmove(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

void CWE126_Buffer_Overread__wchar_t_declare_memmove_45_bad()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    wmemset(dataBadBuffer, L'A', 50-1); /* fill with 'A's */
    dataBadBuffer[50-1] = L'\0'; /* null terminate */
    wmemset(dataGoodBuffer, L'A', 100-1); /* fill with 'A's */
    dataGoodBuffer[100-1] = L'\0'; /* null terminate */
    /* FLAW: Set data pointer to a small buffer */
    data = dataBadBuffer;
    CWE126_Buffer_Overread__wchar_t_declare_memmove_45_badData = data;
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
    CWE126_Buffer_Overread__wchar_t_declare_memmove_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif