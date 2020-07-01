/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_console_ifstream_82a.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: console Read input from the console
 * GoodSource: Use a fixed file name
 * Sinks: ifstream
 *    BadSink : Open the file named in data using ifstream::open()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE23_Relative_Path_Traversal__wchar_t_console_ifstream_82.h"

namespace CWE23_Relative_Path_Traversal__wchar_t_console_ifstream_82
{


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[FILENAME_MAX] = BASEPATH;
    data = dataBuffer;
    /* FIX: Use a fixed file name */
    wcscat(data, L"file.txt");
    CWE23_Relative_Path_Traversal__wchar_t_console_ifstream_82_base* baseObject = new CWE23_Relative_Path_Traversal__wchar_t_console_ifstream_82_goodG2B;
    baseObject->action(data);
    delete baseObject;
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

using namespace CWE23_Relative_Path_Traversal__wchar_t_console_ifstream_82; /* so that we can use good and bad easily */

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
