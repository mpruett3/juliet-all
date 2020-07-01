/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE620_Unverified_Password_Change__w32_17.c
Label Definition File: CWE620_Unverified_Password_Change__w32.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 620 Unverified Password Change
 * Sinks: w32NetUserSetInfo
 *    GoodSink: Require old password to set new password using NetUserChangePassword()
 *    BadSink : Set new password without verifying the old one using NetUserSetInfo()
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <lm.h>
#pragma comment(lib, "netapi32.lib")
#define USERNAME L"cwe620testuser"


#ifndef OMITGOOD

/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            wchar_t oldPassword[256];
            wchar_t newPassword[256];
            NET_API_STATUS status;
            printWLine(L"Enter old password: ");
            if (fwscanf(stdin, L"%255s", oldPassword) != 1)
            {
                oldPassword[0] = L'\0';
            }
            printWLine(L"Enter new password: ");
            if (fwscanf(stdin, L"%255s", newPassword) != 1)
            {
                newPassword[0] = L'\0';
            }
            /* FIX: Verify the old password when setting the new password */
            status = NetUserChangePassword(NULL, USERNAME, oldPassword, newPassword);
            if(status == NERR_Success)
            {
                printWLine(L"Success!");
            }
            else
            {
                wprintf(L"NetUserChangePassword failed.  Status = %u = 0x%x\n", status, status);
            }
        }
    }
}

void CWE620_Unverified_Password_Change__w32_17_good()
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
    CWE620_Unverified_Password_Change__w32_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif