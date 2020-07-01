/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72b.cpp
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * BadSource: listen_socket Read the password using a listen socket (server side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    GoodSink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    BadSink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */

using namespace std;

namespace CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_72
{

#ifndef OMITBAD

void badSink(vector<char *> passwordVector)
{
    /* copy password out of passwordVector */
    char * password = passwordVector[2];
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


} /* close namespace */
