/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE620_Unverified_Password_Change__w32_09.c
Label Definition File: CWE620_Unverified_Password_Change__w32.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 620 Unverified Password Change
 * Sinks: w32NetUserSetInfo
 *    GoodSink: Require old password to set new password using NetUserChangePassword()
 *    BadSink : Set new password without verifying the old one using NetUserSetInfo()
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <lm.h>
#pragma comment(lib, "netapi32.lib")
#define USERNAME L"cwe620testuser"


#ifndef OMITGOOD

/* good1() uses if(GLOBAL_CONST_FALSE) instead of if(GLOBAL_CONST_TRUE) */
static void good1()
{
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
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

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_TRUE)
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

void CWE620_Unverified_Password_Change__w32_09_good()
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
    CWE620_Unverified_Password_Change__w32_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif