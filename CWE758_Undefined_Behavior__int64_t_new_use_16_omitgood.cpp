/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__int64_t_new_use_16.cpp
Label Definition File: CWE758_Undefined_Behavior.new.label.xml
Template File: point-flaw-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: new_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

namespace CWE758_Undefined_Behavior__int64_t_new_use_16
{

#ifndef OMITBAD

void bad()
{
    while(1)
    {
        {
            int64_t * pointer = new int64_t;
            int64_t data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            delete pointer;
            printLongLongLine(data);
        }
        break;
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE758_Undefined_Behavior__int64_t_new_use_16; /* so that we can use good and bad easily */

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
