/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_for_loop_72b.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE400_Resource_Exhaustion__fgets_for_loop_72
{

#ifndef OMITBAD

void badSink(vector<int> countVector)
{
    /* copy count out of countVector */
    int count = countVector[2];
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
