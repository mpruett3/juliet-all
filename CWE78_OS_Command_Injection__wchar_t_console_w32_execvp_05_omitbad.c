/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_console_w32_execvp_05.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-05.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sink: w32_execvp
 *    BadSink : execute command with wexecvp
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define COMMAND_INT_PATH L"%WINDIR%\\system32\\cmd.exe"
#define COMMAND_INT L"cmd.exe"
#define COMMAND_ARG1 L"/c"
#define COMMAND_ARG2 L"dir "
#define COMMAND_ARG3 data
#else /* NOT _WIN32 */
#include <unistd.h>
#define COMMAND_INT_PATH L"/bin/sh"
#define COMMAND_INT L"sh"
#define COMMAND_ARG1 L"-c"
#define COMMAND_ARG2 L"ls "
#define COMMAND_ARG3 data
#endif

#include <process.h>
#define EXECVP _wexecvp

/* The two variables below are not defined as "const", but are never
 * assigned any other value, so a tool should be able to identify that
 * reads of these will always return their initialized values.
 */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */


#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the staticTrue to staticFalse */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = COMMAND_ARG2;
    data = dataBuffer;
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Append a fixed string to data (not user / external input) */
        wcscat(data, L"*.*");
    }
    {
        wchar_t *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* wexecvp - searches for the location of the command among
         * the directories specified by the PATH environment variable */
        /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
        EXECVP(COMMAND_INT, args);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = COMMAND_ARG2;
    data = dataBuffer;
    if(staticTrue)
    {
        /* FIX: Append a fixed string to data (not user / external input) */
        wcscat(data, L"*.*");
    }
    {
        wchar_t *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* wexecvp - searches for the location of the command among
         * the directories specified by the PATH environment variable */
        /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
        EXECVP(COMMAND_INT, args);
    }
}

void CWE78_OS_Command_Injection__wchar_t_console_w32_execvp_05_good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

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
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE78_OS_Command_Injection__wchar_t_console_w32_execvp_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif