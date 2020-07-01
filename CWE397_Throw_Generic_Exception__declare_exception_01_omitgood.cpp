/*
 * @description Declare that the function throws "exception" rather than a specific exception.  In this test case, we don't actually throw an exception to differentiate it from other test cases.
 * 
 * */

#include "std_testcase.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace CWE397_Throw_Generic_Exception__declare_exception_01 
{

#ifndef OMITBAD

/* maintenance note: this may generate a warning in MSVC++, because MSVC++ ignores exception specifiers */
void bad() throw (exception) /* FLAW: Declare function as throws the top-level STL exception class, which is very generic */
{
    throw range_error("Test"); 
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

using namespace CWE397_Throw_Generic_Exception__declare_exception_01; /* so that we can use good and bad easily */

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