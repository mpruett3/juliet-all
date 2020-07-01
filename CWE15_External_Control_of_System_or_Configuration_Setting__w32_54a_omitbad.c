/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_54a.c
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-54a.tmpl.c
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * BadSource:  Get the hostname from a network socket
 * GoodSource: Get the hostname from a string literal
 * Sink:
 *    BadSink : Set the hostname
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5

#include <windows.h>


#ifndef OMITGOOD

/* good function declaration */
void CWE15_External_Control_of_System_or_Configuration_Setting__w32_54b_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* FIX: get the hostname from a string literal */
    strcpy(data, "hostname");
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_54b_goodG2BSink(data);
}

void CWE15_External_Control_of_System_or_Configuration_Setting__w32_54_good()
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
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_54_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
