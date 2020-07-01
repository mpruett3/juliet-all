/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_22b.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Fixed string
 * Sink: popen
 *    BadSink : Execute command in data using popen()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND L"dir "
#else
#include <unistd.h>
#define FULL_COMMAND L"ls "
#endif

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
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5


#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_22_goodG2B1Global;
extern int CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
wchar_t * CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_22_goodG2B1Source(wchar_t * data)
{
    if(CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_22_goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Append a fixed string to data (not user / external input) */
        wcscat(data, L"*.*");
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
wchar_t * CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_22_goodG2B2Source(wchar_t * data)
{
    if(CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_22_goodG2B2Global)
    {
        /* FIX: Append a fixed string to data (not user / external input) */
        wcscat(data, L"*.*");
    }
    return data;
}

#endif /* OMITGOOD */
