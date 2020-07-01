/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__empty_catch_09.cpp
Label Definition File: CWE390_Error_Without_Action__empty_catch.label.xml
Template File: point-flaw-09.tmpl.cpp
*/
/*
 * @description
 * CWE: 390 Error Without Action
 * Sinks:
 *    GoodSink: Catch and handle the exception if one occurs
 *    BadSink : Catch, but do not handle the possible exception
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <iostream>
#include <stdexcept>

using namespace std;

namespace CWE390_Error_Without_Action__empty_catch_09
{

#ifndef OMITBAD

void bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            try
            {
                string stringHello = "hello";
                string stringSubstring = stringHello.substr(rand(), rand());
                printLine(stringSubstring.c_str());
            }
            catch (out_of_range &)
            {
                /* FLAW: Catch, but do not handle the out_of_range error */
            }
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

using namespace CWE390_Error_Without_Action__empty_catch_09; /* so that we can use good and bad easily */

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
