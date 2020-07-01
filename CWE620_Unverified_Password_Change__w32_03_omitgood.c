/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE620_Unverified_Password_Change__w32_03.c
Label Definition File: CWE620_Unverified_Password_Change__w32.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 620 Unverified Password Change
 * Sinks: w32NetUserSetInfo
 *    GoodSink: Require old password to set new password using NetUserChangePassword()
 *    BadSink : Set new password without verifying the old one using NetUserSetInfo()
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <lm.h>
#pragma comment(lib, "netapi32.lib")
#define USERNAME L"cwe620testuser"

#ifndef OMITBAD

void CWE620_Unverified_Password_Change__w32_03_bad()
{
    if(5==5)
    {
        {
            wchar_t newPassword[256];
            USER_INFO_1003 myUserInfo;
            NET_API_STATUS status;
            myUserInfo.usri1003_password = newPassword;
            printWLine(L"Enter new password: ");
            if (fwscanf(stdin, L"%255s", myUserInfo.usri1003_password) != 1)
            {
                myUserInfo.usri1003_password[0] = L'\0';
            }
            /* FLAW: Set password without verifying the old one */
            status = NetUserSetInfo(NULL, USERNAME, 1003, (LPBYTE)&myUserInfo, NULL);
            if(status == NERR_Success)
            {
                printWLine(L"Success!");
            }
            else
            {
                wprintf(L"NetUserSetInfo failed.  Status = %u = 0x%x\n", status, status);
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
    CWE620_Unverified_Password_Change__w32_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
