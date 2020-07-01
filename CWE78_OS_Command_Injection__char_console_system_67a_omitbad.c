/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_system_67a.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sinks: system
 *    BadSink : Execute command in data using system()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE78_OS_Command_Injection__char_console_system_67_structType
{
    char * structFirst;
} CWE78_OS_Command_Injection__char_console_system_67_structType;


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_console_system_67b_goodG2BSink(CWE78_OS_Command_Injection__char_console_system_67_structType myStruct);

static void goodG2B()
{
    char * data;
    CWE78_OS_Command_Injection__char_console_system_67_structType myStruct;
    char data_buf[100] = FULL_COMMAND;
    data = data_buf;
    /* FIX: Append a fixed string to data (not user / external input) */
    strcat(data, "*.*");
    myStruct.structFirst = data;
    CWE78_OS_Command_Injection__char_console_system_67b_goodG2BSink(myStruct);
}

void CWE78_OS_Command_Injection__char_console_system_67_good()
{
    goodG2B();
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
    CWE78_OS_Command_Injection__char_console_system_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
