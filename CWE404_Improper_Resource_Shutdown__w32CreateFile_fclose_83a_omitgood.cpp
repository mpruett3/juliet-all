/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83a.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-83a.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: fclose
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83.h"

namespace CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83
{

#ifndef OMITBAD

void bad()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83_bad badObject(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_83; /* so that we can use good and bad easily */

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