/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_22b.c
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-22b.tmpl.c
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

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5


#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_goodG2B1Global;
extern int CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
char * CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_goodG2B1Source(char * data)
{
    if(CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_goodG2B1Global)
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

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
char * CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_goodG2B2Source(char * data)
{
    if(CWE15_External_Control_of_System_or_Configuration_Setting__w32_22_goodG2B2Global)
    {
        /* FIX: get the hostname from a string literal */
        strcpy(data, "hostname");
    }
    return data;
}

#endif /* OMITGOOD */
