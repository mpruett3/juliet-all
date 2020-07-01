/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE534_Info_Exposure_Debug_Log__w32_char_03.c
Label Definition File: CWE534_Info_Exposure_Debug_Log__w32.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 534 Information Exposure Through Debug Log Files
 * Sinks:
 *    GoodSink: Write to the log, but do not write the password
 *    BadSink : Write to the log and include the password
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#ifndef OMITBAD

void CWE534_Info_Exposure_Debug_Log__w32_char_03_bad()
{
    if(5==5)
    {
        {
            char password[100] = "";
            size_t passwordLen = 0;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            FILE * pFile = fopen("debug.txt", "a+");
            if (fgets(password, 100, stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                password[0] = '\0';
            }
            /* Remove the carriage return from the string that is inserted by fgets() */
            passwordLen = strlen(password);
            if (passwordLen > 0)
            {
                password[passwordLen-1] = '\0';
            }
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
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
            /* FLAW: Write sensitive data to the log */
            fprintf(pFile, "User attempted access with password: %s\n", password);
            if (pFile)
            {
                fclose(pFile);
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
    CWE534_Info_Exposure_Debug_Log__w32_char_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif