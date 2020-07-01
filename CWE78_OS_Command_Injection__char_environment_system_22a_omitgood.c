/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_environment_system_22a.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Fixed string
 * Sink: system
 *    BadSink : Execute command in data using system()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND "dir "
#else
#include <unistd.h>
#define FULL_COMMAND "ls "
#endif

#ifdef _WIN32
#define SYSTEM system
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE78_OS_Command_Injection__char_environment_system_22_badGlobal = 0;

char * CWE78_OS_Command_Injection__char_environment_system_22_badSource(char * data);

void CWE78_OS_Command_Injection__char_environment_system_22_bad()
{
    char * data;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    CWE78_OS_Command_Injection__char_environment_system_22_badGlobal = 1; /* true */
    data = CWE78_OS_Command_Injection__char_environment_system_22_badSource(data);
    /* POTENTIAL FLAW: Execute command in data possibly leading to command injection */
    if (SYSTEM(data) != 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
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
    CWE78_OS_Command_Injection__char_environment_system_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
