/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_vprintf_52b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: console Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vprintf with a format string
 *    BadSink : vprintf without a format string
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_console_vprintf_52c_goodG2BSink(char * data);

void CWE134_Uncontrolled_Format_String__char_console_vprintf_52b_goodG2BSink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_console_vprintf_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_console_vprintf_52c_goodB2GSink(char * data);

void CWE134_Uncontrolled_Format_String__char_console_vprintf_52b_goodB2GSink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_console_vprintf_52c_goodB2GSink(data);
}

#endif /* OMITGOOD */