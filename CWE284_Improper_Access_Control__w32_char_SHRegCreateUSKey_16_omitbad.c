/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_16.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: SHRegCreateUSKey
 *    GoodSink: Create a registry key using SHRegCreateUSKeyA() without excessive privileges
 *    BadSink : Create a registry key using SHRegCreateUSKeyA() with excessive privileges
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "shlwapi" )
#include <shlwapi.h>


#ifndef OMITGOOD

/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
    {
        {
            char * keyName = "TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            /* FIX: Call SHRegCreateUSKeyA() without KEY_ALL_ACCESS as the 2nd parameter to limit access */
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
        break;
    }
}

void CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_16_good()
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
    CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif