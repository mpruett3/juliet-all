/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE615_Info_Exposure_by_Comment__w32_17.c
Label Definition File: CWE615_Info_Exposure_by_Comment__w32.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 615 Information Exposure by Comment
 * Sinks:
 *    GoodSink: Do not place username and password in comment
 *    BadSink : Information exposure by comment
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#define PASSWORD "ABCD1234!"
#define USERNAME "XXXXX Smith!"

#ifndef OMITBAD

void CWE615_Info_Exposure_by_Comment__w32_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            size_t passwordLen = 0;
            HANDLE hUser;
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        USERNAME,
                        domain,
                        PASSWORD,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &hUser) != 0)
            {
                /* FLAW: expose username and password in comment*/
                /* Logged in XXXXX Smith using password ABCD1234 */
                printLine("User logged in successfully" );
                CloseHandle(hUser);
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
    CWE615_Info_Exposure_by_Comment__w32_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif