/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22a.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
int CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22_badGlobal = 0;

void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22_badSink(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("BadSource_fopen.txt", "w+");
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22_badGlobal = 1; /* true */
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22_badSink(data);
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
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif