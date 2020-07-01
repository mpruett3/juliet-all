/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_62a.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-62a.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using CreateFile() and CloseHandle()
 * GoodSource: Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

namespace CWE675_Duplicate_Operations_on_Resource__w32CreateFile_62
{

#ifndef OMITBAD

/* bad function declaration */
void badSource(HANDLE &data);

void bad()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    badSource(data);
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE675_Duplicate_Operations_on_Resource__w32CreateFile_62; /* so that we can use good and bad easily */

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
