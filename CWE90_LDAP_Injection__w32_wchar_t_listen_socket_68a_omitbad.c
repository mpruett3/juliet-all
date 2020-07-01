/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

#include <Winldap.h>

#pragma comment(lib, "wldap32")

wchar_t * CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68_badData;
wchar_t * CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68_goodG2BData;


#ifndef OMITGOOD

/* good function declarations */
void CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[256] = L"";
    data = dataBuffer;
    /* FIX: Use a fixed file name */
    wcscat(data, L"Doe, XXXXX");
    CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68_goodG2BData = data;
    CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68b_goodG2BSink();
}

void CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68_good()
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
    CWE90_LDAP_Injection__w32_wchar_t_listen_socket_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
