/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_console_execlp_64a.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sinks: execlp
 *    BadSink : execute command with wexeclp
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
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

#ifdef _WIN32
#include <process.h>
#define EXECLP _wexeclp
#else /* NOT _WIN32 */
#define EXECLP execlp
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__wchar_t_console_execlp_64b_badSink(void * dataVoidPtr);

void CWE78_OS_Command_Injection__wchar_t_console_execlp_64_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = COMMAND_ARG2;
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    CWE78_OS_Command_Injection__wchar_t_console_execlp_64b_badSink(&data);
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
    CWE78_OS_Command_Injection__wchar_t_console_execlp_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif