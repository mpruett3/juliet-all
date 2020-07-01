/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_33.cpp
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * BadSource:  Get the hostname from a network socket
 * GoodSource: Get the hostname from a string literal
 * Sinks:
 *    BadSink : Set the hostname
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5

#include <windows.h>

namespace CWE15_External_Control_of_System_or_Configuration_Setting__w32_33
{


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * &dataRef = data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* FIX: get the hostname from a string literal */
    strcpy(data, "hostname");
    {
        char * data = dataRef;
        /* POTENTIAL FLAW: set the hostname to data obtained from a potentially external source */
        if (!SetComputerNameA(data))
        {
            printLine("Failure setting computer name");
            exit(1);
        }
    }
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */
#ifdef INCLUDEMAIN

using namespace CWE15_External_Control_of_System_or_Configuration_Setting__w32_33; /* so that we can use good and bad easily */

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