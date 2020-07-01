/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_wchar_t_62b.cpp
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"ABCD1234!"

namespace CWE259_Hard_Coded_Password__w32_wchar_t_62
{

#ifndef OMITBAD

void badSource(wchar_t * &password)
{
    /* FLAW: Use a hardcoded password */
    wcscpy(password, PASSWORD);
}

#endif /* OMITBAD */


} /* close namespace */
