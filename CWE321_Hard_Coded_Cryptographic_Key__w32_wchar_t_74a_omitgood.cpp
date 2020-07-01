/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_74a.cpp
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-74a.tmpl.cpp
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sinks:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#define CRYPTO_KEY L"Hardcoded"

using namespace std;

namespace CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_74
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(map<int, wchar_t *> cryptoKeyMap);

void bad()
{
    wchar_t * cryptoKey;
    map<int, wchar_t *> cryptoKeyMap;
    wchar_t cryptoKeyBuffer[100] = L"";
    cryptoKey = cryptoKeyBuffer;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    wcscpy(cryptoKey, CRYPTO_KEY);
    /* Put cryptoKey in a map */
    cryptoKeyMap[0] = cryptoKey;
    cryptoKeyMap[1] = cryptoKey;
    cryptoKeyMap[2] = cryptoKey;
    badSink(cryptoKeyMap);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_74; /* so that we can use good and bad easily */

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
