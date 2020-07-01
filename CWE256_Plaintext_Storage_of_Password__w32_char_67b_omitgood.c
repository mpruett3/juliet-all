/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_char_67b.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 256 Plaintext Storage of Password
 * BadSource:  Read the password from a file
 * GoodSource: Read the password from a file and decrypt it
 * Sinks:
 *    GoodSink: Decrypt the password then authenticate the user using LogonUserA()
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>
#include <wincrypt.h>
#pragma comment(lib, "advapi32")
#pragma comment(lib, "crypt32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */

typedef struct _CWE256_Plaintext_Storage_of_Password__w32_char_67_structType
{
    char * structFirst;
} CWE256_Plaintext_Storage_of_Password__w32_char_67_structType;

#ifndef OMITBAD

void CWE256_Plaintext_Storage_of_Password__w32_char_67b_badSink(CWE256_Plaintext_Storage_of_Password__w32_char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    {
        HANDLE pHandle;
        char * username = "User";
        char * domain = "Domain";
        /* POTENTIAL FLAW: Attempt to login user with password from the source */
        if (LogonUserA(
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

