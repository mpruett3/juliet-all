/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__connect_socket_22b.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

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
#define IP_ADDRESS "127.0.0.1"
#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)


#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE617_Reachable_Assertion__connect_socket_22_goodG2B1Global;
extern int CWE617_Reachable_Assertion__connect_socket_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
int CWE617_Reachable_Assertion__connect_socket_22_goodG2B1Source(int data)
{
    if(CWE617_Reachable_Assertion__connect_socket_22_goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a value greater than the assert value */
        data = ASSERT_VALUE+1;
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
int CWE617_Reachable_Assertion__connect_socket_22_goodG2B2Source(int data)
{
    if(CWE617_Reachable_Assertion__connect_socket_22_goodG2B2Global)
    {
        /* FIX: Use a value greater than the assert value */
        data = ASSERT_VALUE+1;
    }
    return data;
}

#endif /* OMITGOOD */
