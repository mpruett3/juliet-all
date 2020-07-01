/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_console_54c.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-54c.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: console Read input from the console
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE90_LDAP_Injection__w32_char_console_54d_badSink(char * data);

void CWE90_LDAP_Injection__w32_char_console_54c_badSink(char * data)
{
    CWE90_LDAP_Injection__w32_char_console_54d_badSink(data);
}

#endif /* OMITBAD */
