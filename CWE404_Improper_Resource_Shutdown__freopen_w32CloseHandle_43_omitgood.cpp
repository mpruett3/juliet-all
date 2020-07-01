/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_43.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <windows.h>

namespace CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_43
{

#ifndef OMITBAD

static void badSource(FILE * &data)
{
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("BadSource_freopen.txt","w+",stdin);
}

void bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    badSource(data);
    if (data != NULL)
    {
        /* FLAW: Attempt to close the file using CloseHandle() instead of fclose() */
        CloseHandle((HANDLE)data);
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_43; /* so that we can use good and bad easily */

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