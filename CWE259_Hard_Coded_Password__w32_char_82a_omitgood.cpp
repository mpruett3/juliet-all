/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_char_82a.cpp
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE259_Hard_Coded_Password__w32_char_82.h"

#define PASSWORD "ABCD1234!"

namespace CWE259_Hard_Coded_Password__w32_char_82
{

#ifndef OMITBAD

void bad()
{
    char * password;
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    /* FLAW: Use a hardcoded password */
    strcpy(password, PASSWORD);
    CWE259_Hard_Coded_Password__w32_char_82_base* baseObject = new CWE259_Hard_Coded_Password__w32_char_82_bad;
    baseObject->action(password);
    delete baseObject;
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE259_Hard_Coded_Password__w32_char_82; /* so that we can use good and bad easily */

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
