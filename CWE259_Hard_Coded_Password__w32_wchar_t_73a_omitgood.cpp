/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_wchar_t_73a.cpp
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

#define PASSWORD L"ABCD1234!"

using namespace std;

namespace CWE259_Hard_Coded_Password__w32_wchar_t_73
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(list<wchar_t *> passwordList);

void bad()
{
    wchar_t * password;
    list<wchar_t *> passwordList;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    /* FLAW: Use a hardcoded password */
    wcscpy(password, PASSWORD);
    /* Put password in a list */
    passwordList.push_back(password);
    passwordList.push_back(password);
    passwordList.push_back(password);
    badSink(passwordList);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE259_Hard_Coded_Password__w32_wchar_t_73; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif