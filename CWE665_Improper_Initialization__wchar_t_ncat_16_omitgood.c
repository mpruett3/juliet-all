/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_ncat_16.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: ncat
 *    BadSink : Copy string to data using wcsncat
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE665_Improper_Initialization__wchar_t_ncat_16_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    while(1)
    {
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
        break;
    }
    {
        size_t sourceLen;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        sourceLen = wcslen(source);
        /* POTENTIAL FLAW: If data is not initialized properly, wcsncat() may not function correctly */
        wcsncat(data, source, sourceLen);
        printWLine(data);
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__wchar_t_ncat_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
