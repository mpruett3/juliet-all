/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE676_Use_of_Potentially_Dangerous_Function__basic_02.cpp
Label Definition File: CWE676_Use_of_Potentially_Dangerous_Function__basic.label.xml
Template File: point-flaw-02.tmpl.cpp
*/
/*
 * @description
 * CWE: 676 Use of Potentially Dangerous Function
 * Sinks:
 *    GoodSink: Use cin after specifying the length of the input
 *    BadSink : Use cin without specifying the length of the input
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <iostream>

using namespace std;

#define CHAR_BUFFER_SIZE 10

namespace CWE676_Use_of_Potentially_Dangerous_Function__basic_02
{

#ifndef OMITBAD

void bad()
{
    if(1)
    {
        {
            char charBuffer[CHAR_BUFFER_SIZE];
            /* FLAW: using cin in an inherently dangerous fashion */
            /* INCIDENTAL CWE120 Buffer Overflow since cin extraction is unbounded. */
            cin >> charBuffer;
            charBuffer[CHAR_BUFFER_SIZE-1] = '\0';
            printLine(charBuffer);
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

using namespace CWE676_Use_of_Potentially_Dangerous_Function__basic_02; /* so that we can use good and bad easily */

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
