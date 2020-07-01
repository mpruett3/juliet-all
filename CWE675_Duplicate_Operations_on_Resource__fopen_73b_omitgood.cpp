/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_73b.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: fopen Open and close a file using fopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE675_Duplicate_Operations_on_Resource__fopen_73
{

#ifndef OMITBAD

void badSink(list<FILE *> dataList)
{
    /* copy data out of dataList */
    FILE * data = dataList.back();
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

#endif /* OMITBAD */


} /* close namespace */
