/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_console_printf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: console Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: wprintf with "%s" as the first argument and data as the second
 *    BadSink : wprintf with only data as an argument
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_console_printf_68_badData;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_console_printf_68_goodG2BData;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_console_printf_68_goodB2GData;

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__wchar_t_console_printf_68b_badSink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_console_printf_68_badData;
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    wprintf(data);
}

#endif /* OMITBAD */

