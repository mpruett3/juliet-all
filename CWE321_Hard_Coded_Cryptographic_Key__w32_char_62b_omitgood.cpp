/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_62b.cpp
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sinks:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CRYPTO_KEY "Hardcoded"

namespace CWE321_Hard_Coded_Cryptographic_Key__w32_char_62
{

#ifndef OMITBAD

void badSource(char * &cryptoKey)
{
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    strcpy(cryptoKey, CRYPTO_KEY);
}

#endif /* OMITBAD */


} /* close namespace */
