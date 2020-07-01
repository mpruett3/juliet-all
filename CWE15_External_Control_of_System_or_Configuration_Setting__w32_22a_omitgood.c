/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_22a.c
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * BadSource:  Get the hostname from a network socket
 * GoodSource: Get the hostname from a string literal
 * Sink:
 *    BadSink : Set the hostname
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_badGlobal = 0;

char * CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_badSource(char * data);

void CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_badGlobal = 1; /* true */
    data = CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_badSource(data);
    /* POTENTIAL FLAW: set the hostname to data obtained from a potentially external source */
    if (!SetComputerNameA(data))
    {
        printLine("Failure setting computer name");
        exit(1);
    }
}

#endif /* OMITBAD */


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
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
