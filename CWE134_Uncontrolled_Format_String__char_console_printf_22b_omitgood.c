/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_printf_22b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: console Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE134_Uncontrolled_Format_String__char_console_printf_22_badGlobal;

void CWE134_Uncontrolled_Format_String__char_console_printf_22_badSink(char * data)
{
    if(CWE134_Uncontrolled_Format_String__char_console_printf_22_badGlobal)
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);
    }
}

#endif /* OMITBAD */

