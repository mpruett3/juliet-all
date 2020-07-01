/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_file_vfprintf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfwprintf with a format string
 *    BadSink : vfwprintf without a format string
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_file_vfprintf_68_badData;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_file_vfprintf_68_goodG2BData;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_file_vfprintf_68_goodB2GData;

#ifndef OMITBAD

static void badVaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_file_vfprintf_68b_badSink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_file_vfprintf_68_badData;
    badVaSink(data, data);
}

#endif /* OMITBAD */

