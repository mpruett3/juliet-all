/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32_close_45.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: w32_close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static FILE * CWE404_Improper_Resource_Shutdown__freopen_w32_close_45_badData;
static FILE * CWE404_Improper_Resource_Shutdown__freopen_w32_close_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    FILE * data = CWE404_Improper_Resource_Shutdown__freopen_w32_close_45_badData;
    if (data != NULL)
    {
        /* FLAW: Attempt to close the file using close() instead of fclose() */
        _close((int)data);
    }
}

void CWE404_Improper_Resource_Shutdown__freopen_w32_close_45_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_45_badData = data;
    badSink();
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
