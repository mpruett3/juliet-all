/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_18.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: w32ImpersonateNamedPipeClient
 *    GoodSink: Correctly check if ImpersonateNamedPipeClient() failed
 *    BadSink : Incorrectly check if ImpersonateNamedPipeClient() failed
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#include <windows.h>
#pragma comment(lib, "advapi32")
#define BUFFER_SIZE 1024

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_18_bad()
{
    goto sink;
sink:
    {
        char * pipeName = "\\\\.\\pipe\\mypipe";
        HANDLE hPipe = INVALID_HANDLE_VALUE;
        hPipe = CreateNamedPipeA(
                    pipeName,
                    FILE_FLAG_FIRST_PIPE_INSTANCE,
                    PIPE_TYPE_MESSAGE |
                    PIPE_READMODE_MESSAGE |
                    PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFFER_SIZE,
                    BUFFER_SIZE,
                    NMPWAIT_USE_DEFAULT_WAIT,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        /* FLAW: ImpersonateNamedPipeClient() might fail, in which case the return value will be 0 (false), but
         * we are checking to see if the return value is greater than zero (which will be true) */
        if (ImpersonateNamedPipeClient(hPipe) > 0)
        {
            exit(1);
        }
        CloseHandle(hPipe);
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_w32ImpersonateNamedPipeClient_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif