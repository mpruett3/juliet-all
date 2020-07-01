/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_char_22b.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sink:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "ABCD1234!"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE259_Hard_Coded_Password__w32_char_22_badGlobal;

char * CWE259_Hard_Coded_Password__w32_char_22_badSource(char * password)
{
    if(CWE259_Hard_Coded_Password__w32_char_22_badGlobal)
    {
        /* FLAW: Use a hardcoded password */
        strcpy(password, PASSWORD);
    }
    return password;
}

#endif /* OMITBAD */

