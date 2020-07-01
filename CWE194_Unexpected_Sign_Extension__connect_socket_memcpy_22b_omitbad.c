/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_22b.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
#define CLOSE_SOCKET closesocket
#else /* NOT _WIN32 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#endif

#define TCP_PORT 27015
/* Must be at least 8 for atoi() to work properly */
#define CHAR_ARRAY_SIZE 8
#define IP_ADDRESS "127.0.0.1"


#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_22_goodG2B1Global;
extern int CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
short CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_22_goodG2B1Source(short data)
{
    if(CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_22_goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
short CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_22_goodG2B2Source(short data)
{
    if(CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_22_goodG2B2Global)
    {
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
    }
    return data;
}

#endif /* OMITGOOD */
