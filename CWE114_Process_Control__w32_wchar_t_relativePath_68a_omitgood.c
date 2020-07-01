/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_relativePath_68a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: relativePath Hard code the relative pathname to the library
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

wchar_t * CWE114_Process_Control__w32_wchar_t_relativePath_68_badData;
wchar_t * CWE114_Process_Control__w32_wchar_t_relativePath_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE114_Process_Control__w32_wchar_t_relativePath_68b_badSink();

void CWE114_Process_Control__w32_wchar_t_relativePath_68_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FLAW: Specify just the file name for the library, not the full path */
    wcscpy(data, L"winsrv.dll");
    CWE114_Process_Control__w32_wchar_t_relativePath_68_badData = data;
    CWE114_Process_Control__w32_wchar_t_relativePath_68b_badSink();
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
    CWE114_Process_Control__w32_wchar_t_relativePath_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
