/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_CreateProcess_04.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: CreateProcess
 *    GoodSink: Create a process using CreateProcessA() with quotes for the executable path
 *    BadSink : Create a process using CreateProcessA() without quotes for the executable path
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE272_Least_Privilege_Violation__w32_char_CreateProcess_04_bad()
{
    if(STATIC_CONST_TRUE)
    {
        {
            STARTUPINFOA si;
            PROCESS_INFORMATION pi;
            /* FLAW: The commandLine parameter to CreateProcess() contains a space in it and does not
               surround the executable path with quotes.  A malicious executable could be run because
               of the way the function parses spaces. The process will attempt to run "Program.exe,"
               if it exists, instead of the intended "GoodApp.exe" */
            if( !CreateProcessA(NULL,
                                "C:\\Program Files\\GoodApp arg1 arg2",
                                NULL,
                                NULL,
                                FALSE,
                                0,
                                NULL,
                                NULL,
                                &si,
                                &pi))
            {
                printLine("CreateProcess failed");
                return;
            }
            else
            {
                printLine("CreateProcess successful");
            }
            /* Wait until child process exits. */
            WaitForSingleObject(pi.hProcess, INFINITE);
            /* Close process and thread handles.*/
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
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
    CWE272_Least_Privilege_Violation__w32_char_CreateProcess_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif