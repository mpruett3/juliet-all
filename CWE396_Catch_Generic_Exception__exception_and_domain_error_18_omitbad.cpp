/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE396_Catch_Generic_Exception__exception_and_domain_error_18.cpp
Label Definition File: CWE396_Catch_Generic_Exception.label.xml
Template File: point-flaw-18.tmpl.cpp
*/
/*
 * @description
 * CWE: 396 Catch Generic Exception
 * Sinks: exception_and_domain_error
 *    GoodSink: Catch specific exceptions
 *    BadSink : Catch exception, which will get any exception, before catching domain_error, which is more specific and therefore will never catch anything
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <stdexcept> /* for out_of_range and domain_error */

using namespace std; /* allow easy references to out_of_range and domain_error */

namespace CWE396_Catch_Generic_Exception__exception_and_domain_error_18
{


#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
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
    catch (out_of_range &)
    {
        /* FIX: specify each catch individually */
        printLine("out_of_range");
    }
    catch (domain_error &)
    {
        printLine("domain_error");
        return;
    }
    printLine("ok");
}

void good()
{
    good1();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE396_Catch_Generic_Exception__exception_and_domain_error_18; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif