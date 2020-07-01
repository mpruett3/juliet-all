/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_wchar_t_22a.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
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
int CWE259_Hard_Coded_Password__w32_wchar_t_22_badGlobal = 0;

wchar_t * CWE259_Hard_Coded_Password__w32_wchar_t_22_badSource(wchar_t * password);

void CWE259_Hard_Coded_Password__w32_wchar_t_22_bad()
{
    wchar_t * password;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    CWE259_Hard_Coded_Password__w32_wchar_t_22_badGlobal = 1; /* true */
    password = CWE259_Hard_Coded_Password__w32_wchar_t_22_badSource(password);
    {
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* POTENTIAL FLAW: Attempt to login user with password from the source (which may be hardcoded) */
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
    CWE259_Hard_Coded_Password__w32_wchar_t_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
