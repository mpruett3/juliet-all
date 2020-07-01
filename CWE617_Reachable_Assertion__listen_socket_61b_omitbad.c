/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__listen_socket_61b.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
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
#else
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
#define LISTEN_BACKLOG 5
#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int CWE617_Reachable_Assertion__listen_socket_61b_goodG2BSource(int data)
{
    /* FIX: Use a value greater than the assert value */
    data = ASSERT_VALUE+1;
    return data;
}

#endif /* OMITGOOD */