/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_console_61b.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: console Read input from the console
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH "%SystemRoot%\\system32"
#define PUTENV _putenv
#else
#define NEW_PATH "/bin"
#define PUTENV putenv
#endif


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
char * CWE427_Uncontrolled_Search_Path_Element__char_console_61b_goodG2BSource(char * data)
{
    /* FIX: Set the path as the "system" path */
    strcat(data, NEW_PATH);
    return data;
}

#endif /* OMITGOOD */
