/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_for_loop_81a.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE400_Resource_Exhaustion__rand_for_loop_81.h"

namespace CWE400_Resource_Exhaustion__rand_for_loop_81
{

#ifndef OMITBAD

void bad()
{
    int count;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Set count to a random value */
    count = RAND32();
    const CWE400_Resource_Exhaustion__rand_for_loop_81_base& baseObject = CWE400_Resource_Exhaustion__rand_for_loop_81_bad();
    baseObject.action(count);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE400_Resource_Exhaustion__rand_for_loop_81; /* so that we can use good and bad easily */

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
