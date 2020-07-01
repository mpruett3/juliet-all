/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_15.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegOpenKeyEx
 *    GoodSink: Open a registry key using RegOpenKeyExA() and HKEY_CURRENT_USER
 *    BadSink : Open a registry key using RegOpenKeyExA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_15_bad()
{
    switch(6)
    {
    case 6:
    {
        char * keyName = "TEST\\TestKey";
        HKEY hKey;
        /* FLAW: Call RegOpenKeyExA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
        if (RegOpenKeyExA(
                    HKEY_LOCAL_MACHINE,
                    keyName,
                    0,
                    KEY_WRITE,
                    &hKey) != ERROR_SUCCESS)
        {
            printLine("Registry key could not be opened");
        }
        else
        {
            printLine("Registry key opened successfully");
            RegCloseKey(hKey);
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
    CWE272_Least_Privilege_Violation__w32_char_RegOpenKeyEx_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
