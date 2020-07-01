/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67a.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 256 Plaintext Storage of Password
 * BadSource:  Read the password from a file
 * GoodSource: Read the password from a file and decrypt it
 * Sinks:
 *    GoodSink: Decrypt the password then authenticate the user using LogonUserW()
 *    BadSink : Authenticate the user using LogonUserW()
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

typedef struct _CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_structType
{
    wchar_t * structFirst;
} CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67b_badSink(CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_structType myStruct);

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_bad()
{
    wchar_t * data;
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_structType myStruct;
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
    myStruct.structFirst = data;
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67b_badSink(myStruct);
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
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
