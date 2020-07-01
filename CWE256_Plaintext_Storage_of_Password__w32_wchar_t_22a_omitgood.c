/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22a.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sinks-22a.tmpl.c
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
int CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22_badGlobal = 0;

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22_badSink(wchar_t * data);

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22_bad()
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
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22_badGlobal = 1; /* true */
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22_badSink(data);
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
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
