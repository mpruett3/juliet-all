/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__struct_new_use_13.cpp
Label Definition File: CWE758_Undefined_Behavior.new.label.xml
Template File: point-flaw-13.tmpl.cpp
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: new_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

namespace CWE758_Undefined_Behavior__struct_new_use_13
{

#ifndef OMITBAD

void bad()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            twoIntsStruct * pointer = new twoIntsStruct;
            twoIntsStruct data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            delete pointer;
            printIntLine(data.intOne);
            printIntLine(data.intTwo);
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

using namespace CWE758_Undefined_Behavior__struct_new_use_13; /* so that we can use good and bad easily */

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
