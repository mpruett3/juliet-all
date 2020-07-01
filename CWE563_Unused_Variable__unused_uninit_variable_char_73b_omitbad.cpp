/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_char_73b.cpp
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE563_Unused_Variable__unused_uninit_variable_char_73
{


#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<char> dataList)
{
    char data = dataList.back();
    /* FIX: Initialize then use data */
    data = 'C';
    printHexCharLine(data);
}

#endif /* OMITGOOD */

} /* close namespace */
