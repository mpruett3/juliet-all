/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53b.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-53b.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * BadSource:  Add values to the list, including the number zero
 * GoodSource: Add value to the list that are not zero
 * Sinks:
 *    GoodSink: Iterate through the list without attempting to clear its contents
 *    BadSink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <list>
#include <iostream>

using namespace std;

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_53
{

#ifndef OMITBAD

/* bad function declaration */
void badSink_c(list<int>  data);

void badSink_b(list<int>  data)
{
    badSink_c(data);
}

#endif /* OMITBAD */


} /* close namespace */
