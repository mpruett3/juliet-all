/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE247_Reliance_on_DNS_Lookups_in_Security_Decision__w32_15.c
Label Definition File: CWE247_Reliance_on_DNS_Lookups_in_Security_Decision__w32.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 247 Reliance on DNS Lookups in a Security Decision
 * Sinks:
 *    GoodSink: Log host name without using it in a security decision
 *    BadSink : Use the reverse DNS of the client to determine whether to allow the connection
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5
#define SECRET_HOSTNAME "www.domain.nonexistanttld"


#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
    {
        WSADATA wsaData;
        BOOL wsaDataInit = FALSE;
        SOCKET listenSocket = INVALID_SOCKET;
        SOCKET client = INVALID_SOCKET;
        struct sockaddr_in service;
        struct sockaddr_in serviceClient;
        int serviceClientLen;
        struct hostent *hostInfo;
        FILE * pFile;
        do
        {
            if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
            {
                break;
            }
            wsaDataInit = TRUE;
            listenSocket = socket(PF_INET, SOCK_STREAM, 0);
            if (listenSocket == INVALID_SOCKET)
            {
                break;
            }
            memset(&service, 0, sizeof(service));
            service.sin_family = AF_INET;
            service.sin_addr.s_addr = INADDR_ANY;
            service.sin_port = htons(LISTEN_PORT);
            if (SOCKET_ERROR == bind(listenSocket, (struct sockaddr*)&service, sizeof(service)))
            {
                break;
            }
            if (SOCKET_ERROR == listen(listenSocket, LISTEN_BACKLOG))
            {
                break;
            }
            serviceClientLen = sizeof(serviceClient);
            client = accept(listenSocket, (struct sockaddr*)&serviceClient, &serviceClientLen);
            if (client == INVALID_SOCKET)
            {
                break;
            }
            if (serviceClient.sin_family != AF_INET)
            {
                break;
            }
            hostInfo = gethostbyaddr((char*)&serviceClient.sin_addr, sizeof(serviceClient.sin_addr), AF_INET);
            if (hostInfo == NULL)
            {
                break;
            }
            if (hostInfo->h_name == NULL)
            {
                break;
            }
            printLine(hostInfo->h_name);
            /* FIX: Copy the host name to a log - do not attempt to use the host name in a security decision */
            pFile = fopen("log.txt", "a+");
            fprintf(pFile, "Host name: %s\n", hostInfo->h_name);
            fclose(pFile);
        }
        while (0);
        if (client != INVALID_SOCKET)
        {
            closesocket(client);
        }
        if (listenSocket != INVALID_SOCKET)
        {
            closesocket(listenSocket);
        }
        if (wsaDataInit)
        {
            WSACleanup();
        }
    }
    break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        WSADATA wsaData;
        BOOL wsaDataInit = FALSE;
        SOCKET listenSocket = INVALID_SOCKET;
        SOCKET client = INVALID_SOCKET;
        struct sockaddr_in service;
        struct sockaddr_in serviceClient;
        int serviceClientLen;
        struct hostent *hostInfo;
        FILE * pFile;
        do
        {
            if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
            {
                break;
            }
            wsaDataInit = TRUE;
            listenSocket = socket(PF_INET, SOCK_STREAM, 0);
            if (listenSocket == INVALID_SOCKET)
            {
                break;
            }
            memset(&service, 0, sizeof(service));
            service.sin_family = AF_INET;
            service.sin_addr.s_addr = INADDR_ANY;
            service.sin_port = htons(LISTEN_PORT);
            if (SOCKET_ERROR == bind(listenSocket, (struct sockaddr*)&service, sizeof(service)))
            {
                break;
            }
            if (SOCKET_ERROR == listen(listenSocket, LISTEN_BACKLOG))
            {
                break;
            }
            serviceClientLen = sizeof(serviceClient);
            client = accept(listenSocket, (struct sockaddr*)&serviceClient, &serviceClientLen);
            if (client == INVALID_SOCKET)
            {
                break;
            }
            if (serviceClient.sin_family != AF_INET)
            {
                break;
            }
            hostInfo = gethostbyaddr((char*)&serviceClient.sin_addr, sizeof(serviceClient.sin_addr), AF_INET);
            if (hostInfo == NULL)
            {
                break;
            }
            if (hostInfo->h_name == NULL)
            {
                break;
            }
            printLine(hostInfo->h_name);
            /* FIX: Copy the host name to a log - do not attempt to use the host name in a security decision */
            pFile = fopen("log.txt", "a+");
            fprintf(pFile, "Host name: %s\n", hostInfo->h_name);
            fclose(pFile);
        }
        while (0);
        if (client != INVALID_SOCKET)
        {
            closesocket(client);
        }
        if (listenSocket != INVALID_SOCKET)
        {
            closesocket(listenSocket);
        }
        if (wsaDataInit)
        {
            WSACleanup();
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE247_Reliance_on_DNS_Lookups_in_Security_Decision__w32_15_good()
{
    good1();
    good2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE247_Reliance_on_DNS_Lookups_in_Security_Decision__w32_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif