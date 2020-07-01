/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE15_External_Control_of_System_or_Configuration_Setting__w32_61b.c
Label Definition File: CWE15_External_Control_of_System_or_Configuration_Setting__w32.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 15 External Control of System or Configuration Setting
 * BadSource:  Get the hostname from a network socket
 * GoodSource: Get the hostname from a string literal
 * Sinks:
 *    BadSink : Set the hostname
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5

#include <windows.h>


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
char * CWE15_External_Control_of_System_or_Configuration_Setting__w32_61b_goodG2BSource(char * data)
{
    /* FIX: get the hostname from a string literal */
    strcpy(data, "hostname");
    return data;
}

#endif /* OMITGOOD */
