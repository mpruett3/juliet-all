/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_connect_socket_w32_vsnprintf_54e.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-54e.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Copy a fixed string into data
 * Sinks: w32_vsnprintf
 *    GoodSink: vsnprintf with a format string
 *    BadSink : vsnprintf without a format string
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
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
static void goodG2BVaSink(char * data, ...)
{
    {
        char dest[100] = "";
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vsnprintf(dest, 100-1, data, args);
        va_end(args);
        printLine(dest);
    }
}

void CWE134_Uncontrolled_Format_String__char_connect_socket_w32_vsnprintf_54e_goodG2BSink(char * data)
{
    goodG2BVaSink(data, data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2GVaSink(char * data, ...)
{
    {
        char dest[100] = "";
        va_list args;
        va_start(args, data);
        /* FIX: Specify the format disallowing a format string vulnerability */
        vsnprintf(dest, 100-1, "%s", args);
        va_end(args);
        printLine(dest);
    }
}

void CWE134_Uncontrolled_Format_String__char_connect_socket_w32_vsnprintf_54e_goodB2GSink(char * data)
{
    goodB2GVaSink(data, data);
}

#endif /* OMITGOOD */