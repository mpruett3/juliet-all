/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_fscanf_divide_74b.cpp
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sinks: divide
 *    GoodSink: Check for zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE369_Divide_by_Zero__int_fscanf_divide_74
{

#ifndef OMITBAD

void badSink(map<int, int> dataMap)
{
    /* copy data out of dataMap */
    int data = dataMap[2];
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

#endif /* OMITBAD */


} /* close namespace */
