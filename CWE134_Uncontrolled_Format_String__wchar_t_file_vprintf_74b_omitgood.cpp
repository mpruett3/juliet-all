/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_file_vprintf_74b.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vwprintf with a format string
 *    BadSink : vwprintf without a format string
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */
#include <stdarg.h>
#include <map>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

using namespace std;

namespace CWE134_Uncontrolled_Format_String__wchar_t_file_vprintf_74
{

#ifndef OMITBAD

static void badVaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vwprintf(data, args);
        va_end(args);
    }
}

void badSink(map<int, wchar_t *> dataMap)
{
    /* copy data out of dataMap */
    wchar_t * data = dataMap[2];
    badVaSink(data, data);
}

#endif /* OMITBAD */


} /* close namespace */