/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_int64_t_73b.cpp
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE563_Unused_Variable__unused_init_variable_int64_t_73
{


#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<int64_t> dataList)
{
    int64_t data = dataList.back();
    /* FIX: Use data */
    printLongLongLine(data);
}

#endif /* OMITGOOD */

} /* close namespace */
