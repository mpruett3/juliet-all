/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_twoIntsStruct_73a.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#ifndef _WIN32
#include <wchar.h>
#endif

using namespace std;

namespace CWE401_Memory_Leak__new_twoIntsStruct_73
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(list<twoIntsStruct *> dataList);

void bad()
{
    twoIntsStruct * data;
    list<twoIntsStruct *> dataList;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twoIntsStruct;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printStructLine(data);
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    badSink(dataList);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_twoIntsStruct_73; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
