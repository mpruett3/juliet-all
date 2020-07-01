/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_file_snprintf_53b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: snprintf
 *    GoodSink: snwprintf with "%s" as the third argument and data as the fourth
 *    BadSink : snwprintf with data as the third argument
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF snprintf
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_file_snprintf_53c_badSink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_file_snprintf_53b_badSink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_file_snprintf_53c_badSink(data);
}

#endif /* OMITBAD */
