/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_connect_socket_system_84a.cpp
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Fixed string
 * Sinks: system
 *    BadSink : Execute command in data using system()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_connect_socket_system_84.h"

namespace CWE78_OS_Command_Injection__wchar_t_connect_socket_system_84
{


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100] = FULL_COMMAND;
    data = data_buf;
    CWE78_OS_Command_Injection__wchar_t_connect_socket_system_84_goodG2B * goodG2BObject =  new CWE78_OS_Command_Injection__wchar_t_connect_socket_system_84_goodG2B(data);
    delete goodG2BObject;
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE78_OS_Command_Injection__wchar_t_connect_socket_system_84; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif