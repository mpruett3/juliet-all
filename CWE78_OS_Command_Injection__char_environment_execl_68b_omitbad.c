/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_environment_execl_68b.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Fixed string
 * Sink: execl
 *    BadSink : execute command with execl
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define COMMAND_INT_PATH "%WINDIR%\\system32\\cmd.exe"
#define COMMAND_INT "cmd.exe"
#define COMMAND_ARG1 "/c"
#define COMMAND_ARG2 "dir "
#define COMMAND_ARG3 data
#else /* NOT _WIN32 */
#include <unistd.h>
#define COMMAND_INT_PATH "/bin/sh"
#define COMMAND_INT "sh"
#define COMMAND_ARG1 "-c"
#define COMMAND_ARG2 "ls "
#define COMMAND_ARG3 data
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifdef _WIN32
#include <process.h>
#define EXECL _execl
#else /* NOT _WIN32 */
#define EXECL execl
#endif

extern char * CWE78_OS_Command_Injection__char_environment_execl_68_badData;
extern char * CWE78_OS_Command_Injection__char_environment_execl_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_environment_execl_68b_goodG2BSink()
{
    char * data = CWE78_OS_Command_Injection__char_environment_execl_68_goodG2BData;
    /* execl - specify the path where the command is located */
    /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
    EXECL(COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL);
}

#endif /* OMITGOOD */