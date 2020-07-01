/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22a.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

#pragma comment(lib, "advapi32.lib")

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22_badGlobal = 0;

wchar_t * CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22_badSource(wchar_t * password);

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22_bad()
{
    wchar_t * password;
    /* Initialize Data */
    password = L"";
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22_badGlobal = 1; /* true */
    password = CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22_badSource(password);
    {
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* POTENTIAL FLAW: Sensitive data possibly improperly locked */
        free(password);
    }
}

#endif /* OMITBAD */


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
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
