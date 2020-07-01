/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_fscanf_73b.cpp
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE127_Buffer_Underread__CWE839_fscanf_73
{

#ifndef OMITBAD

void badSink(list<int> dataList)
{
    /* copy data out of dataList */
    int data = dataList.back();
    {
        int buffer[10] = { 0 };
        /* POTENTIAL FLAW: Attempt to access a negative index of the array
         * This check does not check to see if the array index is negative */
        if (data < 10)
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is too big.");
        }
    }
}

#endif /* OMITBAD */


} /* close namespace */
