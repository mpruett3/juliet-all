/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_43.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE675_Duplicate_Operations_on_Resource__freopen_43
{

#ifndef OMITBAD

static void badSource(FILE * &data)
{
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
}

void bad()
{
    FILE * data;
    data = NULL; /* Initialize data */
    badSource(data);
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE675_Duplicate_Operations_on_Resource__freopen_43; /* so that we can use good and bad easily */

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