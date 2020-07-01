/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE510_Trapdoor__network_connection_08.c
Label Definition File: CWE510_Trapdoor.badonly.label.xml
Template File: point-flaw-badonly-08.tmpl.c
*/
/*
 * @description
 * CWE: 510 Trapdoor
 * Sinks: network_connection
 *    BadSink : The presence of a network connection (client side)
 *      BadOnly (No GoodSink)
 * Flow Variant: 08 Control flow: if(staticReturnsTrue())
 *
 * */

#include "std_testcase.h"

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
#define IP_ADDRESS "123.123.123.123"

/* The function below always return the same value, so a tool
   should be able to identify that calls to this function will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}


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
