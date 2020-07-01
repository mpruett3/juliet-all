/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_CreateProcess_01.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: CreateProcess
 *    GoodSink: Create a process using CreateProcessA() with quotes for the executable path
 *    BadSink : Create a process using CreateProcessA() without quotes for the executable path
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )


#ifndef OMITGOOD

static void good1()
{
    {
        STARTUPINFOA si;
        PROCESS_INFORMATION pi;
        /* FIX: The commandLine parameter to CreateProcess() contains quotes surrounding the
           executable path. */
        if( !CreateProcessA(NULL,
                            "\"C:\\Program Files\\GoodApp\" arg1 arg2",
                            NULL,
                            NULL,
                            FALSE,
                            0,
                            NULL,
                            NULL,
                            &si,
                            &pi))
        {
            printf( "CreateProcess failed (%d).\n", GetLastError() );
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

void CWE272_Least_Privilege_Violation__w32_char_CreateProcess_01_good()
{
    good1();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE272_Least_Privilege_Violation__w32_char_CreateProcess_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif