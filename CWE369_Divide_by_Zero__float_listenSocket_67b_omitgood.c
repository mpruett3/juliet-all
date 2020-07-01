/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_listenSocket_67b.c
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: listenSocket Read data using a listen socket (server side)
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

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
#define CHAR_ARRAY_SIZE 20

typedef struct _CWE369_Divide_by_Zero__float_listenSocket_67_structType
{
    float structFirst;
} CWE369_Divide_by_Zero__float_listenSocket_67_structType;

#ifndef OMITBAD

void CWE369_Divide_by_Zero__float_listenSocket_67b_badSink(CWE369_Divide_by_Zero__float_listenSocket_67_structType myStruct)
{
    float data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
}

#endif /* OMITBAD */

