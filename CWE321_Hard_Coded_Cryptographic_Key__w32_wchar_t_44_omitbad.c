/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_44.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-44.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sinks:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define CRYPTO_KEY L"Hardcoded"

#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink(wchar_t * cryptoKey)
{
    {
        HCRYPTPROV hCryptProv;
        HCRYPTKEY hKey;
        HCRYPTHASH hHash;
        wchar_t toBeEncrypted[] = L"String to be encrypted";
        DWORD encryptedLen = wcslen(toBeEncrypted)*sizeof(wchar_t);
        BYTE encrypted[200];    /* buffer should be larger than toBeEncrypted to have room for IV and padding */
        /* Copy plaintext (without NUL terminator) into byte buffer */
        memcpy(encrypted, toBeEncrypted, encryptedLen);
        /* Try to get a context with and without a new key set */
        if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENHANCED_PROV, PROV_RSA_AES, 0))
        {
            if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENHANCED_PROV, PROV_RSA_AES, CRYPT_NEWKEYSET))
            {
                printLine("Error in acquiring cryptographic context");
                exit(1);
            }
        }
        /* Create Hash handle */
        if(!CryptCreateHash(hCryptProv, CALG_SHA_256, 0, 0, &hHash))
        {
            printLine("Error in creating hash");
            exit(1);
        }
        /* Hash the cryptoKey */
        if(!CryptHashData(hHash, (BYTE *) cryptoKey, wcslen(cryptoKey)*sizeof(wchar_t), 0))
        {
            printLine("Error in hashing cryptoKey");
            exit(1);
        }
        /* Derive an AES key from the Hashed cryptoKey */
        if(!CryptDeriveKey(hCryptProv, CALG_AES_256, hHash, 0, &hKey))
        {
            printLine("Error in CryptDeriveKey");
            exit(1);
        }
        /* POTENTIAL FLAW: Possibly using a hardcoded crypto key */
        /* Use the derived key to encrypt something */
        if(!CryptEncrypt(hKey, (HCRYPTHASH)NULL, 1, 0, encrypted, &encryptedLen, sizeof(encrypted)))
        {
            printLine("Error in CryptEncrypt");
            exit(1);
        }
        /* use encrypted block */
        printBytesLine(encrypted, encryptedLen);
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
    }
}

static void goodG2B()
{
    wchar_t * cryptoKey;
    void (*funcPtr) (wchar_t *) = goodG2BSink;
    wchar_t cryptoKeyBuffer[100] = L"";
    cryptoKey = cryptoKeyBuffer;
    {
        size_t cryptoKeyLen = wcslen(cryptoKey);
        /* if there is room in cryptoKey, read into it from the console */
        if(100-cryptoKeyLen > 1)
        {
            /* FIX: Obtain the hash input from the console */
            if (fgetws(cryptoKey+cryptoKeyLen, (int)(100-cryptoKeyLen), stdin) == NULL)
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                cryptoKey[cryptoKeyLen] = L'\0';
            }
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            cryptoKeyLen = wcslen(cryptoKey);
            if (cryptoKeyLen > 0)
            {
                cryptoKey[cryptoKeyLen-1] = L'\0';
            }
        }
    }
    funcPtr(cryptoKey);
}

void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_44_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

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
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_44_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif