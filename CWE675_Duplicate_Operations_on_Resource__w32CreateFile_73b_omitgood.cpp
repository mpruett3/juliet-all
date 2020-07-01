/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_73b.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using CreateFile() and CloseHandle()
 * GoodSource: Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <windows.h>

using namespace std;

namespace CWE675_Duplicate_Operations_on_Resource__w32CreateFile_73
{

#ifndef OMITBAD

void badSink(list<HANDLE> dataList)
{
    /* copy data out of dataList */
    HANDLE data = dataList.back();
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

#endif /* OMITBAD */


} /* close namespace */
