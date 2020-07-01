/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_vprintf_53b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vprintf with a format string
 *    BadSink : vprintf without a format string
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_environment_vprintf_53c_badSink(char * data);

void CWE134_Uncontrolled_Format_String__char_environment_vprintf_53b_badSink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_environment_vprintf_53c_badSink(data);
}

#endif /* OMITBAD */
