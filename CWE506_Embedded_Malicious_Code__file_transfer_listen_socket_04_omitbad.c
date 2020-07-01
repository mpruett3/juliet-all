/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__file_transfer_listen_socket_04.c
Label Definition File: CWE506_Embedded_Malicious_Code__file_transfer.badonly.label.xml
Template File: point-flaw-badonly-04.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: listen_socket
 *    BadSink : Send file contents using a listen socket (server side)
 *      BadOnly (No GoodSink)
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE)
 *
 * */

#include "std_testcase.h"

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
#define FILENAME "conf.txt"

/* The variable below is declared "const", so a tool should
   be able to identify that reads of it will always return its
   initialized value. */
static const int STATIC_CONST_TRUE = 1; /* true */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
    return 0;
}

#endif
