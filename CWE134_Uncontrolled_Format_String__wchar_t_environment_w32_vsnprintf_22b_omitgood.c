/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: w32_vsnprintf
 *    GoodSink: _vsnwprintf with a format string
 *    BadSink : _vsnwprintf without a format string
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
extern int CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_badGlobal;

void CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_badVaSink(wchar_t * data, ...)
{
    if(CWE134_Uncontrolled_Format_String__wchar_t_environment_w32_vsnprintf_22_badGlobal)
    {
        {
            wchar_t dest[100] = L"";
            va_list args;
            va_start(args, data);
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            _vsnwprintf(dest, 100-1, data, args);
            va_end(args);
            printWLine(dest);
        }
    }
}

#endif /* OMITBAD */

