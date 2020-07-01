/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_TwoIntsClass_45.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-45.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_TwoIntsClass_45
{

static TwoIntsClass * badData;
static TwoIntsClass * goodG2BData;
static TwoIntsClass * goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    TwoIntsClass * data = badData;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

void bad()
{
    TwoIntsClass * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new TwoIntsClass[100];
    /* Initialize and make use of data */
    data[0].intOne = 0;
    data[0].intTwo = 0;
    printIntLine(data[0].intOne);
    printIntLine(data[0].intTwo);
    badData = data;
    badSink();
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_array_TwoIntsClass_45; /* so that we can use good and bad easily */

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