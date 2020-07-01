/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_wchar_t_72b.cpp
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE563_Unused_Variable__unused_uninit_variable_wchar_t_72
{


#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<wchar_t> dataVector)
{
    wchar_t data = dataVector[2];
    /* FIX: Initialize then use data */
    data = L'W';
    printWcharLine(data);
}

#endif /* OMITGOOD */

} /* close namespace */