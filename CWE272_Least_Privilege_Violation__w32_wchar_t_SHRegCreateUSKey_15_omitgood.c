/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_15.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: SHRegCreateUSKey
 *    GoodSink: Create a registry key using SHRegCreateUSKeyW() and SHREGSET_HKCU
 *    BadSink : Create a registry key using SHRegCreateUSKeyW() and SHREGSET_HKLM
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_15_bad()
{
    switch(6)
    {
    case 6:
    {
        wchar_t * keyName = L"TEST\\TestKey";
        HUSKEY hKey;
        /* FLAW: Call SHRegCreateUSKeyW() with SHREGSET_HKLM violating the least privilege principal */
        if (SHRegCreateUSKeyW(
                    keyName,
                    KEY_WRITE,
                    NULL,
                    &hKey,
                    SHREGSET_HKLM) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be created");
        }
        else
        {
            printLine("Registry key created successfully");
            SHRegCloseUSKey(hKey);
        }
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
    CWE272_Least_Privilege_Violation__w32_wchar_t_SHRegCreateUSKey_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif