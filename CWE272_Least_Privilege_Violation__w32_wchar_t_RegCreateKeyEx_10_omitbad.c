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


#ifndef OMITGOOD

/* good1() uses if(globalFalse) instead of if(globalTrue) */
static void good1()
{
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegCreateKeyExW() with HKEY_CURRENT_USER */
            if (RegCreateKeyExW(
                        HKEY_CURRENT_USER,
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

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalTrue)
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegCreateKeyExW() with HKEY_CURRENT_USER */
            if (RegCreateKeyExW(
                        HKEY_CURRENT_USER,
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

void CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKeyEx_10_good()
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
    CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKeyEx_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif