/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_environment_system_62b.cpp
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Fixed string
 * Sinks: system
 *    BadSink : Execute command in data using system()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
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

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

namespace CWE78_OS_Command_Injection__char_environment_system_62
{


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(char * &data)
{
    /* FIX: Append a fixed string to data (not user / external input) */
    strcat(data, "*.*");
}

#endif /* OMITGOOD */

} /* close namespace */