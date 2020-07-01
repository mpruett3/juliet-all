/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_listen_socket_vprintf_22b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vprintf with a format string
 *    BadSink : vprintf without a format string
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
extern int CWE134_Uncontrolled_Format_String__char_listen_socket_vprintf_22_badGlobal;

void CWE134_Uncontrolled_Format_String__char_listen_socket_vprintf_22_badVaSink(char * data, ...)
{
    if(CWE134_Uncontrolled_Format_String__char_listen_socket_vprintf_22_badGlobal)
    {
        {
            va_list args;
            va_start(args, data);
            /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
            vprintf(data, args);
            va_end(args);
        }
    }
}

#endif /* OMITBAD */

