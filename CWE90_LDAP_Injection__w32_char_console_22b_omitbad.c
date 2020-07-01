/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_console_22b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: console Read input from the console
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE90_LDAP_Injection__w32_char_console_22_goodG2B1Global;
extern int CWE90_LDAP_Injection__w32_char_console_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
char * CWE90_LDAP_Injection__w32_char_console_22_goodG2B1Source(char * data)
{
    if(CWE90_LDAP_Injection__w32_char_console_22_goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a fixed file name */
        strcat(data, "Doe, XXXXX");
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
char * CWE90_LDAP_Injection__w32_char_console_22_goodG2B2Source(char * data)
{
    if(CWE90_LDAP_Injection__w32_char_console_22_goodG2B2Global)
    {
        /* FIX: Use a fixed file name */
        strcat(data, "Doe, XXXXX");
    }
    return data;
}

#endif /* OMITGOOD */