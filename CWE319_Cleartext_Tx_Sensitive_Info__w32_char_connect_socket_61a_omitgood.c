/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61a.c
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * BadSource: connect_socket Read the password using a connect socket (client side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    GoodSink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    BadSink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */

#define TCP_PORT 27015
#define IP_ADDRESS "127.0.0.1"

#pragma comment(lib, "advapi32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */

#ifndef OMITBAD

/* bad function declaration */
char * CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61b_badSource(char * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61_bad()
{
    char * password;
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    password = CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61b_badSource(password);
    {
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        /* POTENTIAL FLAW: Using sensitive information that was possibly sent in plaintext over the network */
        if (LogonUserA(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
