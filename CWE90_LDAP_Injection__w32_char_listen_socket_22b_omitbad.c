/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_listen_socket_22b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
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


#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE90_LDAP_Injection__w32_char_listen_socket_22_goodG2B1Global;
extern int CWE90_LDAP_Injection__w32_char_listen_socket_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
char * CWE90_LDAP_Injection__w32_char_listen_socket_22_goodG2B1Source(char * data)
{
    if(CWE90_LDAP_Injection__w32_char_listen_socket_22_goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a fixed file name */
        strcat(data, "Doe, XXXXX");
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
char * CWE90_LDAP_Injection__w32_char_listen_socket_22_goodG2B2Source(char * data)
{
    if(CWE90_LDAP_Injection__w32_char_listen_socket_22_goodG2B2Global)
    {
        /* FIX: Use a fixed file name */
        strcat(data, "Doe, XXXXX");
    }
    return data;
}

#endif /* OMITGOOD */
