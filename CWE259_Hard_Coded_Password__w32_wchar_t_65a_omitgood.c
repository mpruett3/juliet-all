/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_wchar_t_65a.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"ABCD1234!"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#ifndef OMITBAD

/* bad function declaration */
void CWE259_Hard_Coded_Password__w32_wchar_t_65b_badSink(wchar_t * password);

void CWE259_Hard_Coded_Password__w32_wchar_t_65_bad()
{
    wchar_t * password;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = CWE259_Hard_Coded_Password__w32_wchar_t_65b_badSink;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    /* FLAW: Use a hardcoded password */
    wcscpy(password, PASSWORD);
    /* use the function pointer */
    funcPtr(password);
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
    CWE259_Hard_Coded_Password__w32_wchar_t_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif