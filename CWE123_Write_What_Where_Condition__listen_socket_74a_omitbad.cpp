/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__listen_socket_74a.cpp
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-74a.tmpl.cpp
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: listen_socket Overwrite linked list pointers using a listen socket (server side)
 * GoodSource: Don't overwrite linked list pointers
 * Sinks:
 *    BadSink : Remove element from list
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

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

using namespace std;

namespace CWE123_Write_What_Where_Condition__listen_socket_74
{


#ifndef OMITGOOD

/* good function declarations */

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, badStruct> dataMap);

static void goodG2B()
{
    badStruct data;
    map<int, badStruct> dataMap;
    linkedList head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = head.prev;
    head.next = &data.list;
    head.prev = &data.list;
    /* FIX: don't overwrite linked list pointers */
    ; /* empty statement needed by some flow variants */
    /* Put data in a map */
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    goodG2BSink(dataMap);
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE123_Write_What_Where_Condition__listen_socket_74; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif