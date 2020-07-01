/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_vprintf_54b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: console Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vprintf with a format string
 *    BadSink : vprintf without a format string
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_console_vprintf_54c_goodG2BSink(char * data);

void CWE134_Uncontrolled_Format_String__char_console_vprintf_54b_goodG2BSink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_console_vprintf_54c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_console_vprintf_54c_goodB2GSink(char * data);

void CWE134_Uncontrolled_Format_String__char_console_vprintf_54b_goodB2GSink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_console_vprintf_54c_goodB2GSink(data);
}

#endif /* OMITGOOD */