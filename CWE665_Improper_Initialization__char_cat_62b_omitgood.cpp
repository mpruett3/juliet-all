/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_62b.cpp
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: cat
 *    BadSink : Copy string to data using strcat
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE665_Improper_Initialization__char_cat_62
{

#ifndef OMITBAD

void badSource(char * &data)
{
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */


} /* close namespace */