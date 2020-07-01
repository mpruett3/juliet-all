/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68a.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sinks-68a.tmpl.c
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

wchar_t * CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_badData;
wchar_t * CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_goodG2BData;
wchar_t * CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_goodB2GData;

#ifndef OMITBAD

/* bad function declaration */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68b_badSink();

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        FILE *pFile;
        pFile = fopen("passwords.txt", "r");
        if (pFile != NULL)
        {
            /* POTENTIAL FLAW: Read the password from a file */
            if (fgetws(data, 100, pFile) == NULL)
            {
                data[0] = L'\0';
            }
            fclose(pFile);
        }
        else
        {
            data[0] = L'\0';
        }
    }
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_badData = data;
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68b_badSink();
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
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif