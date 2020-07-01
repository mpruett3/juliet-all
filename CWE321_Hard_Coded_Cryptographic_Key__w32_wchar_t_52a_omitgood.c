/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_52a.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-52a.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sink:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#define CRYPTO_KEY L"Hardcoded"

#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")

#ifndef OMITBAD

/* bad function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_52b_badSink(wchar_t * cryptoKey);

void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_52_bad()
{
    wchar_t * cryptoKey;
    wchar_t cryptoKeyBuffer[100] = L"";
    cryptoKey = cryptoKeyBuffer;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    wcscpy(cryptoKey, CRYPTO_KEY);
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_52b_badSink(cryptoKey);
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
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_52_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
