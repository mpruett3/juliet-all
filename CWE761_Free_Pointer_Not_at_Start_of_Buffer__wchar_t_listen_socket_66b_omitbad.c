/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_66b.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * BadSource: listen_socket Read data using a listen socket (server side)
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
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

#define SEARCH_CHAR L'S'


#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_listen_socket_66b_goodB2GSink(wchar_t * dataArray[])
{
    wchar_t * data = dataArray[2];
    {
        size_t i;
        /* FIX: Use a loop variable to traverse through the string pointed to by data */
        for (i=0; i < wcslen(data); i++)
        {
            if (data[i] == SEARCH_CHAR)
            {
                printLine("We have a match!");
                break;
            }
        }
        free(data);
    }
}

#endif /* OMITGOOD */