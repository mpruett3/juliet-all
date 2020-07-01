/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_64a.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE675_Duplicate_Operations_on_Resource__freopen_64b_badSink(void * dataVoidPtr);

void CWE675_Duplicate_Operations_on_Resource__freopen_64_bad()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
    CWE675_Duplicate_Operations_on_Resource__freopen_64b_badSink(&data);
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
    CWE675_Duplicate_Operations_on_Resource__freopen_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif