/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_82a.cpp
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sinks:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE321_Hard_Coded_Cryptographic_Key__w32_char_82.h"

#define CRYPTO_KEY "Hardcoded"

namespace CWE321_Hard_Coded_Cryptographic_Key__w32_char_82
{

#ifndef OMITBAD

void bad()
{
    char * cryptoKey;
    char cryptoKeyBuffer[100] = "";
    cryptoKey = cryptoKeyBuffer;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    strcpy(cryptoKey, CRYPTO_KEY);
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_82_base* baseObject = new CWE321_Hard_Coded_Cryptographic_Key__w32_char_82_bad;
    baseObject->action(cryptoKey);
    delete baseObject;
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE321_Hard_Coded_Cryptographic_Key__w32_char_82; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
