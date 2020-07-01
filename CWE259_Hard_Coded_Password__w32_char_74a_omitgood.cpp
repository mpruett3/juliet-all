/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_char_74a.cpp
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-74a.tmpl.cpp
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>

#define PASSWORD "ABCD1234!"

using namespace std;

namespace CWE259_Hard_Coded_Password__w32_char_74
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(map<int, char *> passwordMap);

void bad()
{
    char * password;
    map<int, char *> passwordMap;
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    /* FLAW: Use a hardcoded password */
    strcpy(password, PASSWORD);
    /* Put password in a map */
    passwordMap[0] = password;
    passwordMap[1] = password;
    passwordMap[2] = password;
    badSink(passwordMap);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE259_Hard_Coded_Password__w32_char_74; /* so that we can use good and bad easily */

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
