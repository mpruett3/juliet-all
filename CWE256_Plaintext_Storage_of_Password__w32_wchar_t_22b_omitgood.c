/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22b.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 256 Plaintext Storage of Password
 * BadSource:  Read the password from a file
 * GoodSource: Read the password from a file and decrypt it
 * Sinks:
 *    GoodSink: Decrypt the password then authenticate the user using LogonUserW()
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>
#include <wincrypt.h>
#pragma comment(lib, "advapi32")
#pragma comment(lib, "crypt32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22_badGlobal;

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22_badSink(wchar_t * data)
{
    if(CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22_badGlobal)
    {
        {
            HANDLE pHandle;
            wchar_t * username = L"User";
            wchar_t * domain = L"Domain";
            /* POTENTIAL FLAW: Attempt to login user with password from the source */
            if (LogonUserW(
                        username,
                        domain,
                        data,
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
}

#endif /* OMITBAD */

