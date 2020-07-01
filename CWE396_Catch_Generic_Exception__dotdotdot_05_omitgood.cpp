/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE396_Catch_Generic_Exception__dotdotdot_05.cpp
Label Definition File: CWE396_Catch_Generic_Exception.label.xml
Template File: point-flaw-05.tmpl.cpp
*/
/*
 * @description
 * CWE: 396 Catch Generic Exception
 * Sinks: dotdotdot
 *    GoodSink: Catch specific exceptions
 *    BadSink : Catch ..., which will catch any exception
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <stdexcept> /* for out_of_range and domain_error */

using namespace std; /* allow easy references to out_of_range and domain_error */

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

namespace CWE396_Catch_Generic_Exception__dotdotdot_05
{

#ifndef OMITBAD

void bad()
{
    if(staticTrue)
    {
        try
        {
            if (rand()%2 == 0)
            {
                throw out_of_range("err1");
            }
            if (rand()%2 == 0)
            {
                throw domain_error("err2");
            }
        }
        catch (...)
        {
            /* FLAW: this catches _everything_, STL exceptions or otherwise */
            printLine("exception");
        }
        printLine("ok");
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE396_Catch_Generic_Exception__dotdotdot_05; /* so that we can use good and bad easily */

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