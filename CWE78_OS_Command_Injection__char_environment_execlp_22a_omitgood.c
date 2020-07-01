/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_environment_execlp_22a.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Fixed string
 * Sink: execlp
 *    BadSink : execute command with execlp
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
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

#ifdef _WIN32
#include <process.h>
#define EXECLP _execlp
#else /* NOT _WIN32 */
#define EXECLP execlp
#endif

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE78_OS_Command_Injection__char_environment_execlp_22_badGlobal = 0;

char * CWE78_OS_Command_Injection__char_environment_execlp_22_badSource(char * data);

void CWE78_OS_Command_Injection__char_environment_execlp_22_bad()
{
    char * data;
    char dataBuffer[100] = COMMAND_ARG2;
    data = dataBuffer;
    CWE78_OS_Command_Injection__char_environment_execlp_22_badGlobal = 1; /* true */
    data = CWE78_OS_Command_Injection__char_environment_execlp_22_badSource(data);
    /* execlp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
    EXECLP(COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG3, NULL);
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
    CWE78_OS_Command_Injection__char_environment_execlp_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
