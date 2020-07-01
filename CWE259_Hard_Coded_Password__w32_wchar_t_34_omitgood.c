/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_wchar_t_34.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"ABCD1234!"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

typedef union
{
    wchar_t * unionFirst;
    wchar_t * unionSecond;
} CWE259_Hard_Coded_Password__w32_wchar_t_34_unionType;

#ifndef OMITBAD

void CWE259_Hard_Coded_Password__w32_wchar_t_34_bad()
{
    wchar_t * password;
    CWE259_Hard_Coded_Password__w32_wchar_t_34_unionType myUnion;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    /* FLAW: Use a hardcoded password */
    wcscpy(password, PASSWORD);
    myUnion.unionFirst = password;
    {
        wchar_t * password = myUnion.unionSecond;
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
    CWE259_Hard_Coded_Password__w32_wchar_t_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif