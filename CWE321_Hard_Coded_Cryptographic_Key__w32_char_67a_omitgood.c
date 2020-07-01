/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_67a.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sinks:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CRYPTO_KEY "Hardcoded"

#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")

typedef struct _CWE321_Hard_Coded_Cryptographic_Key__w32_char_67_structType
{
    char * structFirst;
} CWE321_Hard_Coded_Cryptographic_Key__w32_char_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_67b_badSink(CWE321_Hard_Coded_Cryptographic_Key__w32_char_67_structType myStruct);

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_67_bad()
{
    char * cryptoKey;
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_67_structType myStruct;
    char cryptoKeyBuffer[100] = "";
    cryptoKey = cryptoKeyBuffer;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    strcpy(cryptoKey, CRYPTO_KEY);
    myStruct.structFirst = cryptoKey;
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_67b_badSink(myStruct);
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
