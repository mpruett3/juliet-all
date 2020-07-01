/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKeyEx_10.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegCreateKeyEx
 *    GoodSink: Create a registry key using RegCreateKeyExW() and HKEY_CURRENT_USER
 *    BadSink : Create a registry key using RegCreateKeyExW() and HKEY_LOCAL_MACHINE
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKeyEx_10_bad()
{
    if(globalTrue)
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HKEY hKey;
            /* FLAW: Call RegCreateKeyExW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (RegCreateKeyExW(
                        HKEY_LOCAL_MACHINE,
                        keyName,
                        0,
                        NULL,
                        REG_OPTION_NON_VOLATILE,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        NULL) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                RegCloseKey(hKey);
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
    CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKeyEx_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif