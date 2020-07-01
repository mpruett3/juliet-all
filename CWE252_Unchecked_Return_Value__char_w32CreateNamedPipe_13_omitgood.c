/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_13.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: w32CreateNamedPipe
 *    GoodSink: Check the return value of CreateNamedPipeA() and handle it properly
 *    BadSink : Do not check if CreateNamedPipeA() fails
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#include <windows.h>
#define BUFSIZE 1024

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_13_bad()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            char * pipeName = "\\\\.\\pipe\\mypipe";
            HANDLE hPipe = INVALID_HANDLE_VALUE;
            BOOL fConnected = FALSE;
            hPipe = CreateNamedPipeA(
                        pipeName,
                        FILE_FLAG_FIRST_PIPE_INSTANCE, /* FILE_FLAG_FIRST_PIPE_INSTANCE - this flag must be set */
                        PIPE_TYPE_MESSAGE |
                        PIPE_READMODE_MESSAGE |
                        PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        NMPWAIT_USE_DEFAULT_WAIT,
                        NULL);
            /* FLAW: Do not check the return value */
            fConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hPipe);
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
    CWE252_Unchecked_Return_Value__char_w32CreateNamedPipe_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif