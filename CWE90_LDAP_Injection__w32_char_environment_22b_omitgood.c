/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_environment_22b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE90_LDAP_Injection__w32_char_environment_22_badGlobal;

char * CWE90_LDAP_Injection__w32_char_environment_22_badSource(char * data)
{
    if(CWE90_LDAP_Injection__w32_char_environment_22_badGlobal)
    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = strlen(data);
            char * environment = GETENV(ENV_VARIABLE);
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* POTENTIAL FLAW: Read data from an environment variable */
                strncat(data+dataLen, environment, 256-dataLen-1);
            }
        }
    }
    return data;
}

#endif /* OMITBAD */

