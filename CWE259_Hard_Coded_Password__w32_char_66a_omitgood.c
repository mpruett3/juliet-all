/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_char_66a.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "ABCD1234!"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#ifndef OMITBAD

/* bad function declaration */
void CWE259_Hard_Coded_Password__w32_char_66b_badSink(char * passwordArray[]);

void CWE259_Hard_Coded_Password__w32_char_66_bad()
{
    char * password;
    char * passwordArray[5];
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    /* FLAW: Use a hardcoded password */
    strcpy(password, PASSWORD);
    /* put password in array */
    passwordArray[2] = password;
    CWE259_Hard_Coded_Password__w32_char_66b_badSink(passwordArray);
}

#endif /* OMITBAD */


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
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE259_Hard_Coded_Password__w32_char_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
