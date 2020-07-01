/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_connect_socket_67a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

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


typedef struct _CWE114_Process_Control__w32_wchar_t_connect_socket_67_structType
{
    wchar_t * structFirst;
} CWE114_Process_Control__w32_wchar_t_connect_socket_67_structType;


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_wchar_t_connect_socket_67b_goodG2BSink(CWE114_Process_Control__w32_wchar_t_connect_socket_67_structType myStruct);

static void goodG2B()
{
    wchar_t * data;
    CWE114_Process_Control__w32_wchar_t_connect_socket_67_structType myStruct;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Specify the full pathname for the library */
    wcscpy(data, L"C:\\Windows\\System32\\winsrv.dll");
    myStruct.structFirst = data;
    CWE114_Process_Control__w32_wchar_t_connect_socket_67b_goodG2BSink(myStruct);
}

void CWE114_Process_Control__w32_wchar_t_connect_socket_67_good()
{
    goodG2B();
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
    CWE114_Process_Control__w32_wchar_t_connect_socket_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
