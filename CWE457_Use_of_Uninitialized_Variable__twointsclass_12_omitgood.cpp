/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_12.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass.label.xml
Template File: sources-sinks-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource:  Don't initialize data
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_12
{

#ifndef OMITBAD

void bad()
{
    TwoIntsClass data;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX: Initialize data */
        data.intOne = 1;
        data.intTwo = 2;
    }
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
    else
    {
        /* FIX: Ensure data is initialized before use */
        data.intOne = 1;
        data.intTwo = 2;
        printIntLine(data.intOne);
        printIntLine(data.intTwo);
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_12; /* so that we can use good and bad easily */

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