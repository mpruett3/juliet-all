/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__listen_socket_61b.c
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: listen_socket Overwrite linked list pointers using a listen socket (server side)
 * GoodSource: Don't overwrite linked list pointers
 * Sinks:
 *    BadSink : Remove element from list
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _linkedList
{
    struct _linkedList *next;
    struct _linkedList *prev;
} linkedList;

typedef struct _badStruct
{
    linkedList list;
} badStruct;

static linkedList *linkedListPrev, *linkedListNext;

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

/* goodG2B() uses the GoodSource with the BadSink */
badStruct CWE123_Write_What_Where_Condition__listen_socket_61b_goodG2BSource(badStruct data)
{
    /* FIX: don't overwrite linked list pointers */
    ; /* empty statement needed by some flow variants */
    return data;
}

#endif /* OMITGOOD */
