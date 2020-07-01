/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_65a.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sinks:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define CRYPTO_KEY "Hardcoded"

#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")

#ifndef OMITBAD

/* bad function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_65b_badSink(char * cryptoKey);

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_65_bad()
{
    char * cryptoKey;
    /* define a function pointer */
    void (*funcPtr) (char *) = CWE321_Hard_Coded_Cryptographic_Key__w32_char_65b_badSink;
    char cryptoKeyBuffer[100] = "";
    cryptoKey = cryptoKeyBuffer;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    strcpy(cryptoKey, CRYPTO_KEY);
    /* use the function pointer */
    funcPtr(cryptoKey);
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
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
