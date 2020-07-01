/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_console_67a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: console Read input from the console
 * GoodSource: Use a fixed string
 * Sinks:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")

typedef struct _CWE90_LDAP_Injection__w32_char_console_67_structType
{
    char * structFirst;
} CWE90_LDAP_Injection__w32_char_console_67_structType;


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE90_LDAP_Injection__w32_char_console_67b_goodG2BSink(CWE90_LDAP_Injection__w32_char_console_67_structType myStruct);

static void goodG2B()
{
    char * data;
    CWE90_LDAP_Injection__w32_char_console_67_structType myStruct;
    char dataBuffer[256] = "";
    data = dataBuffer;
    /* FIX: Use a fixed file name */
    strcat(data, "Doe, XXXXX");
    myStruct.structFirst = data;
    CWE90_LDAP_Injection__w32_char_console_67b_goodG2BSink(myStruct);
}

void CWE90_LDAP_Injection__w32_char_console_67_good()
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
    CWE90_LDAP_Injection__w32_char_console_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
