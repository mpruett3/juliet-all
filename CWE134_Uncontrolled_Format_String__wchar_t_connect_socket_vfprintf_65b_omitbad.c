/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_65b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfwprintf with a format string
 *    BadSink : vfwprintf without a format string
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

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


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_65b_goodG2BVaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vfwprintf(stdout, data, args);
        va_end(args);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_65b_goodB2GVaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vfwprintf(stdout, L"%s", args);
        va_end(args);
    }
}

#endif /* OMITGOOD */