/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_53c.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 256 Plaintext Storage of Password
 * BadSource:  Read the password from a file
 * GoodSource: Read the password from a file and decrypt it
 * Sinks:
 *    GoodSink: Decrypt the password then authenticate the user using LogonUserW()
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
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

/* bad function declaration */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_53d_badSink(wchar_t * data);

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_53c_badSink(wchar_t * data)
{
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_53d_badSink(data);
}

#endif /* OMITBAD */
