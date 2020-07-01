/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_68a.c
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * BadSource:  Get the hostname from a network socket
 * GoodSource: Get the hostname from a string literal
 * Sink:
 *    BadSink : Set the hostname
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5

#include <windows.h>

char * CWE15_External_Control_of_System_or_Configuration_Setting__w32_68_badData;
char * CWE15_External_Control_of_System_or_Configuration_Setting__w32_68_goodG2BData;


#ifndef OMITGOOD

/* good function declarations */
void CWE15_External_Control_of_System_or_Configuration_Setting__w32_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* FIX: get the hostname from a string literal */
    strcpy(data, "hostname");
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_68_goodG2BData = data;
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_68b_goodG2BSink();
}

void CWE15_External_Control_of_System_or_Configuration_Setting__w32_68_good()
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
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
