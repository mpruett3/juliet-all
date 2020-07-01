/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__connect_socket_for_loop_73b.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE400_Resource_Exhaustion__connect_socket_for_loop_73
{

#ifndef OMITBAD

void badSink(list<int> countList)
{
    /* copy count out of countList */
    int count = countList.back();
    {
        size_t i = 0;
        /* POTENTIAL FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

#endif /* OMITBAD */


} /* close namespace */
