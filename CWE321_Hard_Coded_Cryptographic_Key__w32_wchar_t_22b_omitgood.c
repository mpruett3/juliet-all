/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_22b.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sink:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#define CRYPTO_KEY L"Hardcoded"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_22_badGlobal;

wchar_t * CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_22_badSource(wchar_t * cryptoKey)
{
    if(CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_22_badGlobal)
    {
        /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
        wcscpy(cryptoKey, CRYPTO_KEY);
    }
    return cryptoKey;
}

#endif /* OMITBAD */

