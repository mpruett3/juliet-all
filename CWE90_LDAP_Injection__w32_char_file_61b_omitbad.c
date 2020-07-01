/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_file_61b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed string
 * Sinks:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
char * CWE90_LDAP_Injection__w32_char_file_61b_goodG2BSource(char * data)
{
    /* FIX: Use a fixed file name */
    strcat(data, "Doe, XXXXX");
    return data;
}

#endif /* OMITGOOD */
