/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_SHRegCreateUSKey_01.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: SHRegCreateUSKey
 *    GoodSink: Create a registry key using SHRegCreateUSKeyA() and SHREGSET_HKCU
 *    BadSink : Create a registry key using SHRegCreateUSKeyA() and SHREGSET_HKLM
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )


#ifndef OMITGOOD

static void good1()
{
    {
        char * keyName = "TEST\\TestKey";
        HUSKEY hKey;
        /* FIX: Call SHRegCreateUSKeyA() with SHREGSET_HKCU */
        if (SHRegCreateUSKeyA(
                    keyName,
                    KEY_WRITE,
                    NULL,
                    &hKey,
                    SHREGSET_HKCU) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be created");
        }
        else
        {
            printLine("Registry key created successfully");
            SHRegCloseUSKey(hKey);
        }
    }
}

void CWE272_Least_Privilege_Violation__w32_char_SHRegCreateUSKey_01_good()
{
    good1();
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
    CWE272_Least_Privilege_Violation__w32_char_SHRegCreateUSKey_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif