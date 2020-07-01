/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_wchar_t_CreateNamedPipe_15.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: CreateNamedPipe
 *    GoodSink: Create a windows pipe using CreateNamedPipeW() ensuring that the pipe won't be created over an existing one
 *    BadSink : Create a windows pipe using CreateNamedPipeW() potentially allowing the pipe to be created over an existing one
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )
#define BUFSIZE 1024
#define PIPE_NAME L"\\\\.\\pipe\\TestPipe"


#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
    {
        HANDLE hPipe;
        wchar_t * pipeName = PIPE_NAME;
        /* FIX: Call CreateNamedPipeW() with PIPE_ACCESS_DUPLEX and FILE_FLAG_FIRST_PIPE_INSTANCE as the 2nd parameter */
        hPipe = CreateNamedPipeW(
                    pipeName,
                    FILE_FLAG_FIRST_PIPE_INSTANCE | PIPE_ACCESS_DUPLEX,
                    PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    0,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            printLine("Windows pipe creation failed");
        }
        else
        {
            printLine("Windows pipe created successfully");
            CloseHandle(hPipe);
        }
    }
    break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        HANDLE hPipe;
        wchar_t * pipeName = PIPE_NAME;
        /* FIX: Call CreateNamedPipeW() with PIPE_ACCESS_DUPLEX and FILE_FLAG_FIRST_PIPE_INSTANCE as the 2nd parameter */
        hPipe = CreateNamedPipeW(
                    pipeName,
                    FILE_FLAG_FIRST_PIPE_INSTANCE | PIPE_ACCESS_DUPLEX,
                    PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    0,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            printLine("Windows pipe creation failed");
        }
        else
        {
            printLine("Windows pipe created successfully");
            CloseHandle(hPipe);
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE284_Improper_Access_Control__w32_wchar_t_CreateNamedPipe_15_good()
{
    good1();
    good2();
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
    CWE284_Improper_Access_Control__w32_wchar_t_CreateNamedPipe_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif