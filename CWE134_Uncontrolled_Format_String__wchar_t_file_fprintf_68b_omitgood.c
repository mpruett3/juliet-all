/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fwprintf with "%s" as the second argument and data as the third
 *    BadSink : fwprintf with data as the second argument
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_68_badData;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_68_goodG2BData;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_68_goodB2GData;

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_68b_badSink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_68_badData;
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

#endif /* OMITBAD */

