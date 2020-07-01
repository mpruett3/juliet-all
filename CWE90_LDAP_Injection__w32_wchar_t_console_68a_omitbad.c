/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_console_68a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: console Read input from the console
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")

wchar_t * CWE90_LDAP_Injection__w32_wchar_t_console_68_badData;
wchar_t * CWE90_LDAP_Injection__w32_wchar_t_console_68_goodG2BData;


#ifndef OMITGOOD

/* good function declarations */
void CWE90_LDAP_Injection__w32_wchar_t_console_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[256] = L"";
    data = dataBuffer;
    /* FIX: Use a fixed file name */
    wcscat(data, L"Doe, XXXXX");
    CWE90_LDAP_Injection__w32_wchar_t_console_68_goodG2BData = data;
    CWE90_LDAP_Injection__w32_wchar_t_console_68b_goodG2BSink();
}

void CWE90_LDAP_Injection__w32_wchar_t_console_68_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

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
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE90_LDAP_Injection__w32_wchar_t_console_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif