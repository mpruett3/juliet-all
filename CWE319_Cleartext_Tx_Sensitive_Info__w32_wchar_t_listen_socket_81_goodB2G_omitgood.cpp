/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_81_goodB2G.cpp
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-81_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * BadSource: listen_socket Read the password using a listen socket (server side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    GoodSink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    BadSink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
