/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_74b.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using open() and close()
 * GoodSource: Open a file using open()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
#include <unistd.h>
# define OPEN open
# define CLOSE close
#endif

using namespace std;

namespace CWE675_Duplicate_Operations_on_Resource__open_74
{

#ifndef OMITBAD

void badSink(map<int, int> dataMap)
{
    /* copy data out of dataMap */
    int data = dataMap[2];
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

#endif /* OMITBAD */


} /* close namespace */
