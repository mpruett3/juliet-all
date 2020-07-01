/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE325_Missing_Required_Cryptographic_Step__w32_CryptEncrypt_15.c
Label Definition File: CWE325_Missing_Required_Cryptographic_Step__w32.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 325 Missing Required Cryptographic Step
 * Sinks: CryptEncrypt
 *    GoodSink: All required cryptographic steps are present
 *    BadSink : Missing call to CryptEncrypt()
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#include <wincrypt.h>

#pragma comment(lib, "advapi32")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */
#define PAYLOAD "plaintext"

#ifndef OMITBAD

void CWE325_Missing_Required_Cryptographic_Step__w32_CryptEncrypt_15_bad()
{
    switch(6)
    {
    case 6:
    {
        BYTE payload[100];
        DWORD payloadLen = strlen(PAYLOAD);
        HCRYPTPROV hCryptProv = (HCRYPTPROV)NULL;
        HCRYPTHASH hHash = (HCRYPTHASH)NULL;
        HCRYPTKEY hKey = (HCRYPTKEY)NULL;
        char hashData[100] = HASH_INPUT;
        do
        {
            /* Copy plaintext into payload buffer */
            memcpy(payload, PAYLOAD, payloadLen);
            /* Aquire a Context */
            if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0))
            {
                break;
            }
            /* Create hash handle */
            if(!CryptCreateHash(hCryptProv, CALG_SHA_256, 0, 0, &hHash))
            {
                break;
            }
            /* Hash the input string */
            if(!CryptHashData(hHash, (BYTE*)hashData, strlen(hashData), 0))
            {
                break;
            }
            /* Derive an AES key from the hash */
            if(!CryptDeriveKey(hCryptProv, CALG_AES_256, hHash, 0, &hKey))
            {
                break;
            }
            /* FLAW: Missing required step (CryptEncrypt) does not encrypt the payload */
        }
        while (0);
        if (hKey)
        {
            CryptDestroyKey(hKey);
        }
        if (hHash)
        {
            CryptDestroyHash(hHash);
        }
        if (hCryptProv)
        {
            CryptReleaseContext(hCryptProv, 0);
        }
        /* Do something with the encrypted data */
        printBytesLine(payload, payloadLen);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
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
    CWE325_Missing_Required_Cryptographic_Step__w32_CryptEncrypt_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
