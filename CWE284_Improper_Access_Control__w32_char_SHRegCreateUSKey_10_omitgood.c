/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_10.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: SHRegCreateUSKey
 *    GoodSink: Create a registry key using SHRegCreateUSKeyA() without excessive privileges
 *    BadSink : Create a registry key using SHRegCreateUSKeyA() with excessive privileges
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "shlwapi" )
#include <shlwapi.h>

#ifndef OMITBAD

void CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_10_bad()
{
    if(globalTrue)
    {
        {
            char * keyName = "TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            /* FLAW: Call SHRegCreateUSKeyA() with KEY_ALL_ACCESS as the 2nd parameter */
            if (SHRegCreateUSKeyA(
                        keyName,
                        KEY_ALL_ACCESS,
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
    CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif