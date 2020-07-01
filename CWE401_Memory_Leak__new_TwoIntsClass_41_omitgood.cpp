/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_TwoIntsClass_41.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-41.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_TwoIntsClass_41
{

#ifndef OMITBAD

static void badSink(TwoIntsClass * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

void bad()
{
    TwoIntsClass * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new TwoIntsClass;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printIntLine(data->intOne);
    printIntLine(data->intTwo);
    badSink(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_TwoIntsClass_41; /* so that we can use good and bad easily */

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
