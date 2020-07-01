/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_34.c
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * BadSource:  Get the hostname from a network socket
 * GoodSource: Get the hostname from a string literal
 * Sinks:
 *    BadSink : Set the hostname
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5

#include <windows.h>

typedef union
{
    char * unionFirst;
    char * unionSecond;
} CWE15_External_Control_of_System_or_Configuration_Setting__w32_34_unionType;


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_34_unionType myUnion;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* FIX: get the hostname from a string literal */
    strcpy(data, "hostname");
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        /* POTENTIAL FLAW: set the hostname to data obtained from a potentially external source */
        if (!SetComputerNameA(data))
        {
            printLine("Failure setting computer name");
            exit(1);
        }
    }
}

void CWE15_External_Control_of_System_or_Configuration_Setting__w32_34_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
