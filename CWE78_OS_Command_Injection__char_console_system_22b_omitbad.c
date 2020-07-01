/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_system_22b.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
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


#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE78_OS_Command_Injection__char_console_system_22_goodG2B1Global;
extern int CWE78_OS_Command_Injection__char_console_system_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
char * CWE78_OS_Command_Injection__char_console_system_22_goodG2B1Source(char * data)
{
    if(CWE78_OS_Command_Injection__char_console_system_22_goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Append a fixed string to data (not user / external input) */
        strcat(data, "*.*");
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
char * CWE78_OS_Command_Injection__char_console_system_22_goodG2B2Source(char * data)
{
    if(CWE78_OS_Command_Injection__char_console_system_22_goodG2B2Global)
    {
        /* FIX: Append a fixed string to data (not user / external input) */
        strcat(data, "*.*");
    }
    return data;
}

#endif /* OMITGOOD */