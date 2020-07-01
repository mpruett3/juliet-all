/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_72b.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfwprintf with a format string
 *    BadSink : vfwprintf without a format string
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */
#include <stdarg.h>
#include <vector>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

using namespace std;

namespace CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_72
{

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

void badSink(vector<wchar_t *> dataVector)
{
    /* copy data out of dataVector */
    wchar_t * data = dataVector[2];
    badVaSink(data, data);
}

#endif /* OMITBAD */


} /* close namespace */
