/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__connect_socket_66a.c
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: connect_socket Overwrite linked list pointers using a connect socket (client side)
 * GoodSource: Don't overwrite linked list pointers
 * Sinks:
 *    BadSink : Remove element from list
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
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
void CWE123_Write_What_Where_Condition__connect_socket_66b_goodG2BSink(badStruct dataArray[]);

static void goodG2B()
{
    badStruct data;
    badStruct dataArray[5];
    linkedList head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = head.prev;
    head.next = &data.list;
    head.prev = &data.list;
    /* FIX: don't overwrite linked list pointers */
    ; /* empty statement needed by some flow variants */
    dataArray[2] = data;
    CWE123_Write_What_Where_Condition__connect_socket_66b_goodG2BSink(dataArray);
}

void CWE123_Write_What_Where_Condition__connect_socket_66_good()
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
    CWE123_Write_What_Where_Condition__connect_socket_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif