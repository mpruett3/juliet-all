/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52b.c
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * BadSource: connect_socket Read the password using a connect socket (client side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    GoodSink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    BadSink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52c_goodG2BSink(wchar_t * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52b_goodG2BSink(wchar_t * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52c_goodG2BSink(password);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52c_goodB2GSink(wchar_t * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52b_goodB2GSink(wchar_t * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_52c_goodB2GSink(password);
}

#endif /* OMITGOOD */