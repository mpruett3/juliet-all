/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__listen_socket_strncpy_74b.cpp
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Positive integer
 * Sinks: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE194_Unexpected_Sign_Extension__listen_socket_strncpy_74
{

#ifndef OMITBAD

void badSink(map<int, short> dataMap)
{
    /* copy data out of dataMap */
    short data = dataMap[2];
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign extension could result in a very large number */
            strncpy(dest, source, data);
            dest[data] = '\0'; /* strncpy() does not always NULL terminate */
        }
        printLine(dest);
    }
}

#endif /* OMITBAD */


} /* close namespace */