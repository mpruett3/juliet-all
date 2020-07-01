/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_listen_socket_fprintf_22b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fprintf with "%s" as the second argument and data as the third
 *    BadSink : fprintf with data as the second argument
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE134_Uncontrolled_Format_String__char_listen_socket_fprintf_22_badGlobal;

void CWE134_Uncontrolled_Format_String__char_listen_socket_fprintf_22_badSink(char * data)
{
    if(CWE134_Uncontrolled_Format_String__char_listen_socket_fprintf_22_badGlobal)
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        fprintf(stdout, data);
    }
}

#endif /* OMITBAD */

