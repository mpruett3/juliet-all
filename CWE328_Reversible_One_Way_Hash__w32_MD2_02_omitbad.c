/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE328_Reversible_One_Way_Hash__w32_MD2_02.c
Label Definition File: CWE328_Reversible_One_Way_Hash__w32.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 328 Reversible One Way Hash
 * Sinks: MD2
 *    GoodSink: Use SHA-512 as a hashing algorithm
 *    BadSink : Use MD2 as a hashing algorithm
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <wincrypt.h>
#pragma comment(lib, "advapi32.lib")

#define PASSWORD_INPUT_SIZE 128
#define SHA512_SUM_SIZE (512 / 8)

#define MD2_SUM_SIZE (128 / 8)


#ifndef OMITGOOD

/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            HCRYPTPROV hCryptProv;
            HCRYPTHASH hHash;
            FILE *pFile = NULL;
            char password[PASSWORD_INPUT_SIZE];
            UCHAR savedHash[SHA512_SUM_SIZE], calcHash[SHA512_SUM_SIZE];
            DWORD hashSize;
            char *replace;
            size_t i;
            pFile = fopen("password.txt", "r");
            if (pFile == NULL)
            {
                exit(1);
            }
            for (i = 0; i < SHA512_SUM_SIZE; i++)
            {
                ULONG val;
                if (fscanf(pFile, "%02x", &val) != 1)
                {
                    fclose(pFile);
                    exit(1);
                }
                if (val > 0xff) /* EXPECTED INCIDENTAL: Reliance on data memory layout, we assume char is at least 8 bits */
                {
                    fclose(pFile);
                    exit(1);
                }
                savedHash[i] = (UCHAR)val;
            }
            fclose(pFile);
            if (fgets(password, PASSWORD_INPUT_SIZE, stdin) == NULL)
            {
                exit(1);
            }
            replace = strchr(password, '\r');
            if (replace)
            {
                *replace = '\0';
            }
            replace = strchr(password, '\n');
            if (replace)
            {
                *replace = '\0';
            }
            if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0))
            {
                exit(1);
            }
            /* FIX: use a non-reversible hash (SHA-512) */
            if (!CryptCreateHash(hCryptProv, CALG_SHA_512, 0, 0, &hHash))
            {
                CryptReleaseContext(hCryptProv, 0);
                exit(1);
            }
            /* EXPECTED INCIDENTAL: We did not salt the password, that may raise flags,
             * the password hash was not securely transmitted (via one form or another),
             * that may raise flags
             */
            if (!CryptHashData(hHash, (BYTE*)password, strlen(password), 0))
            {
                CryptDestroyHash(hHash);
                CryptReleaseContext(hCryptProv, 0);
                exit(1);
            }
            hashSize = SHA512_SUM_SIZE;
            if (!CryptGetHashParam(hHash, HP_HASHVAL, (BYTE*)calcHash, &hashSize, 0))
            {
                CryptDestroyHash(hHash);
                CryptReleaseContext(hCryptProv, 0);
                exit(1);
            }
            if (memcmp(savedHash, calcHash, SHA512_SUM_SIZE * sizeof(UCHAR)) == 0)
            {
                printLine("Access granted");
            }
            else
            {
                printLine("Access denied");
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
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
            HCRYPTPROV hCryptProv;
            HCRYPTHASH hHash;
            FILE *pFile = NULL;
            char password[PASSWORD_INPUT_SIZE];
            UCHAR savedHash[SHA512_SUM_SIZE], calcHash[SHA512_SUM_SIZE];
            DWORD hashSize;
            char *replace;
            size_t i;
            pFile = fopen("password.txt", "r");
            if (pFile == NULL)
            {
                exit(1);
            }
            for (i = 0; i < SHA512_SUM_SIZE; i++)
            {
                ULONG val;
                if (fscanf(pFile, "%02x", &val) != 1)
                {
                    fclose(pFile);
                    exit(1);
                }
                if (val > 0xff) /* EXPECTED INCIDENTAL: Reliance on data memory layout, we assume char is at least 8 bits */
                {
                    fclose(pFile);
                    exit(1);
                }
                savedHash[i] = (UCHAR)val;
            }
            fclose(pFile);
            if (fgets(password, PASSWORD_INPUT_SIZE, stdin) == NULL)
            {
                exit(1);
            }
            replace = strchr(password, '\r');
            if (replace)
            {
                *replace = '\0';
            }
            replace = strchr(password, '\n');
            if (replace)
            {
                *replace = '\0';
            }
            if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0))
            {
                exit(1);
            }
            /* FIX: use a non-reversible hash (SHA-512) */
            if (!CryptCreateHash(hCryptProv, CALG_SHA_512, 0, 0, &hHash))
            {
                CryptReleaseContext(hCryptProv, 0);
                exit(1);
            }
            /* EXPECTED INCIDENTAL: We did not salt the password, that may raise flags,
             * the password hash was not securely transmitted (via one form or another),
             * that may raise flags
             */
            if (!CryptHashData(hHash, (BYTE*)password, strlen(password), 0))
            {
                CryptDestroyHash(hHash);
                CryptReleaseContext(hCryptProv, 0);
                exit(1);
            }
            hashSize = SHA512_SUM_SIZE;
            if (!CryptGetHashParam(hHash, HP_HASHVAL, (BYTE*)calcHash, &hashSize, 0))
            {
                CryptDestroyHash(hHash);
                CryptReleaseContext(hCryptProv, 0);
                exit(1);
            }
            if (memcmp(savedHash, calcHash, SHA512_SUM_SIZE * sizeof(UCHAR)) == 0)
            {
                printLine("Access granted");
            }
            else
            {
                printLine("Access denied");
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
}

void CWE328_Reversible_One_Way_Hash__w32_MD2_02_good()
{
    good1();
    good2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE328_Reversible_One_Way_Hash__w32_MD2_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif