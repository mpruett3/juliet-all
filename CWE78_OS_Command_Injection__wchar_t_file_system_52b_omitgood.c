/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_file_system_52b.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: file Read input from a file
 * GoodSource: Fixed string
 * Sink: system
 *    BadSink : Execute command in data using system()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND L"dir "
#else
#include <unistd.h>
#define FULL_COMMAND L"ls "
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifdef _WIN32
#define SYSTEM _wsystem
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__wchar_t_file_system_52c_badSink(wchar_t * data);

void CWE78_OS_Command_Injection__wchar_t_file_system_52b_badSink(wchar_t * data)
{
    CWE78_OS_Command_Injection__wchar_t_file_system_52c_badSink(data);
}

#endif /* OMITBAD */
