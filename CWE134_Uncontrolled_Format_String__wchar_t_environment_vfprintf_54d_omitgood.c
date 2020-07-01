/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_54d.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfwprintf with a format string
 *    BadSink : vfwprintf without a format string
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_54e_badSink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_54d_badSink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_environment_vfprintf_54e_badSink(data);
}

#endif /* OMITBAD */
