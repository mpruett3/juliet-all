/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__listen_socket_67a.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE617_Reachable_Assertion__listen_socket_67_structType
{
    int structFirst;
} CWE617_Reachable_Assertion__listen_socket_67_structType;


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__listen_socket_67b_goodG2BSink(CWE617_Reachable_Assertion__listen_socket_67_structType myStruct);

static void goodG2B()
{
    int data;
    CWE617_Reachable_Assertion__listen_socket_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than the assert value */
    data = ASSERT_VALUE+1;
    myStruct.structFirst = data;
    CWE617_Reachable_Assertion__listen_socket_67b_goodG2BSink(myStruct);
}

void CWE617_Reachable_Assertion__listen_socket_67_good()
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
    CWE617_Reachable_Assertion__listen_socket_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif