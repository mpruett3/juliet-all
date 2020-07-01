/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_environment_61b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed string
 * Sinks:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
wchar_t * CWE90_LDAP_Injection__w32_wchar_t_environment_61b_goodG2BSource(wchar_t * data)
{
    /* FIX: Use a fixed file name */
    wcscat(data, L"Doe, XXXXX");
    return data;
}

#endif /* OMITGOOD */
