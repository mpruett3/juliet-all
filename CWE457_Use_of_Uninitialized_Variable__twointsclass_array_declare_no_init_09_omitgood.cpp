/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_array_declare_no_init_09.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass_array.label.xml
Template File: sources-sinks-09.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_declare_no_init_09
{

#ifndef OMITBAD

void bad()
{
    TwoIntsClass * data;
    TwoIntsClass dataUninitArray[10];
    data = dataUninitArray;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use data without initializing it */
        for(int i=0; i<10; i++)
        {
            printIntLine(data[i].intOne);
            printIntLine(data[i].intTwo);
        }
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_declare_no_init_09; /* so that we can use good and bad easily */

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
