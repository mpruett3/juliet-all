/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_14.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sinks-14.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check data for NULL before attempting to print data->a
 *    BadSink : Print data->a
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 * */

#include "std_testcase.h"

namespace CWE476_NULL_Pointer_Dereference__class_14
{

#ifndef OMITBAD

void bad()
{
    TwoIntsClass * data;
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Set data to NULL */
        data = NULL;
    }
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printIntLine(data->intOne);
        /* avoid memory leak - deleting a NULL pointer is a no-op in C++ so no need to check for NULL */
        delete data;
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE476_NULL_Pointer_Dereference__class_14; /* so that we can use good and bad easily */

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