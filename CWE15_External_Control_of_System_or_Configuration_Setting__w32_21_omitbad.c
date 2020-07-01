/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_21.c
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-21.tmpl.c
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * BadSource:  Get the hostname from a network socket
 * GoodSource: Get the hostname from a string literal
 * Sink:
 *    BadSink : Set the hostname
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5

#include <windows.h>


#ifndef OMITGOOD

/* The static variables below are used to drive control flow in the source functions. */
static int goodG2B1Static = 0;
static int goodG2B2Static = 0;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
static char * goodG2B1Source(char * data)
{
    if(goodG2B1Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: get the hostname from a string literal */
        strcpy(data, "hostname");
    }
    return data;
}

static void goodG2B1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    goodG2B1Static = 0; /* false */
    data = goodG2B1Source(data);
    /* POTENTIAL FLAW: set the hostname to data obtained from a potentially external source */
    if (!SetComputerNameA(data))
    {
        printLine("Failure setting computer name");
        exit(1);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
static char * goodG2B2Source(char * data)
{
    if(goodG2B2Static)
    {
        /* FIX: get the hostname from a string literal */
        strcpy(data, "hostname");
    }
    return data;
}

static void goodG2B2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    goodG2B2Static = 1; /* true */
    data = goodG2B2Source(data);
    /* POTENTIAL FLAW: set the hostname to data obtained from a potentially external source */
    if (!SetComputerNameA(data))
    {
        printLine("Failure setting computer name");
        exit(1);
    }
}

void CWE15_External_Control_of_System_or_Configuration_Setting__w32_21_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE15_External_Control_of_System_or_Configuration_Setting__w32_21_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
