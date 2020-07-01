/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68b.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 256 Plaintext Storage of Password
 * BadSource:  Read the password from a file
 * GoodSource: Read the password from a file and decrypt it
 * Sinks:
 *    GoodSink: Decrypt the password then authenticate the user using LogonUserW()
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>
#include <wincrypt.h>
#pragma comment(lib, "advapi32")
#pragma comment(lib, "crypt32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */

extern wchar_t * CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_badData;
extern wchar_t * CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_goodG2BData;
extern wchar_t * CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_goodB2GData;

#ifndef OMITBAD

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68b_badSink()
{
    wchar_t * data = CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_badData;
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

#endif /* OMITBAD */

