/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_console_w32_vsnprintf_22b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: console Read input from the console
 * GoodSource: Copy a fixed string into data
 * Sinks: w32_vsnprintf
 *    GoodSink: vsnprintf with a format string
 *    BadSink : vsnprintf without a format string
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE134_Uncontrolled_Format_String__char_console_w32_vsnprintf_22_badGlobal;

void CWE134_Uncontrolled_Format_String__char_console_w32_vsnprintf_22_badVaSink(char * data, ...)
{
    if(CWE134_Uncontrolled_Format_String__char_console_w32_vsnprintf_22_badGlobal)
    {
        {
            char dest[100] = "";
            va_list args;
            va_start(args, data);
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            vsnprintf(dest, 100-1, data, args);
            va_end(args);
            printLine(dest);
        }
    }
}

#endif /* OMITBAD */
