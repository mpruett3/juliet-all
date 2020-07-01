/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_SHRegOpenUSKey_02.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: SHRegOpenUSKey
 *    GoodSink: Open a registry key using SHRegOpenUSKeyA() and HKEY_CURRENT_USER
 *    BadSink : Open a registry key using SHRegOpenUSKeyA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <shlwapi.h>
#pragma comment( lib, "shlwapi" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Violation__w32_char_SHRegOpenUSKey_02_bad()
{
    if(1)
    {
        {
            char * keyName = "TEST\\TestKey";
            HUSKEY hKey;
            /* FLAW: Call SHRegOpenUSKeyA() with HKEY_LOCAL_MACHINE (fIgnoreHKCU == TRUE) violating the least privilege principal */
            if (SHRegOpenUSKeyA(
                        keyName,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        TRUE) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be opened");
            }
            else
            {
                printLine("Registry key opened successfully");
                SHRegCloseUSKey(hKey);
            }
        }
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
    CWE272_Least_Privilege_Violation__w32_char_SHRegOpenUSKey_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
