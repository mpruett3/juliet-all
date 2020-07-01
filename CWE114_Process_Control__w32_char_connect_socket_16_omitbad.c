/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_connect_socket_16.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 16 Control flow: while(1)
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



#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the while statements */
static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    while(1)
    {
        /* FIX: Specify the full pathname for the library */
        strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
        break;
    }
    {
        HMODULE hModule;
        /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryA(data);
        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else
        {
            printLine("Unable to load library");
        }
    }
}

void CWE114_Process_Control__w32_char_connect_socket_16_good()
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
    CWE114_Process_Control__w32_char_connect_socket_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
