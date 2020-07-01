/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__wchar_t_declare_loop_68a.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

wchar_t * CWE127_Buffer_Underread__wchar_t_declare_loop_68_badData;
wchar_t * CWE127_Buffer_Underread__wchar_t_declare_loop_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE127_Buffer_Underread__wchar_t_declare_loop_68b_badSink();

void CWE127_Buffer_Underread__wchar_t_declare_loop_68_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    wmemset(dataBuffer, L'A', 100-1);
    dataBuffer[100-1] = L'\0';
    /* FLAW: Set data pointer to before the allocated memory buffer */
    data = dataBuffer - 8;
    CWE127_Buffer_Underread__wchar_t_declare_loop_68_badData = data;
    CWE127_Buffer_Underread__wchar_t_declare_loop_68b_badSink();
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
    CWE127_Buffer_Underread__wchar_t_declare_loop_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif