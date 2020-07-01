/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_CreateProcessAsUser_18.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: CreateProcessAsUser
 *    GoodSink: Create a process using CreateProcessAsUserA() with quotes for the executable path
 *    BadSink : Create a process using CreateProcessAsUserA() without quotes for the executable path
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#ifndef OMITBAD

void CWE272_Least_Privilege_Violation__w32_char_CreateProcessAsUser_18_bad()
{
    goto sink;
sink:
    {
        STARTUPINFOA si;
        PROCESS_INFORMATION pi;
        HANDLE pHandle = NULL;
        /* FLAW: The commandLine parameter to CreateProcessAsUser() contains a space in it and does not
           surround the executable path with quotes.  A malicious executable could be run because of the
           way the function parses spaces. The process will attempt to run "Program.exe," if it exists,
           instead of the intended "GoodApp.exe"  */
        if(!CreateProcessAsUserA(pHandle,
                                 NULL,
                                 "C:\\Program Files\\GoodApp arg1 arg2",
                                 NULL,
                                 NULL,
                                 FALSE,
                                 DETACHED_PROCESS,
                                 NULL,
                                 NULL,
                                 &si,
                                 &pi))
        {
            printLine("CreateProcessAsUser failed");
            RevertToSelf();
            CloseHandle(pHandle);
            return;
        }
        else
        {
            printLine("CreateProcessAUser successful");
        }
        /* Wait until child process exits. */
        WaitForSingleObject(pi.hProcess, INFINITE);
        /* Close process and thread handles.*/
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        CloseHandle(pHandle);
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
    CWE272_Least_Privilege_Violation__w32_char_CreateProcessAsUser_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif