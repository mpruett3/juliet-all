/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_int_alloca_73a.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE590_Free_Memory_Not_on_Heap__free_int_alloca_73
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(list<int *> dataList);

void bad()
{
    int * data;
    list<int *> dataList;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        int * dataBuffer = (int *)ALLOCA(100*sizeof(int));
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i] = 5;
            }
        }
        data = dataBuffer;
    }
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    badSink(dataList);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE590_Free_Memory_Not_on_Heap__free_int_alloca_73; /* so that we can use good and bad easily */

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