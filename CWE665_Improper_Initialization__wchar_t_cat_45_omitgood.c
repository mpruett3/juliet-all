/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_45.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static wchar_t * CWE665_Improper_Initialization__wchar_t_cat_45_badData;
static wchar_t * CWE665_Improper_Initialization__wchar_t_cat_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    wchar_t * data = CWE665_Improper_Initialization__wchar_t_cat_45_badData;
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, source);
        printWLine(data);
    }
}

void CWE665_Improper_Initialization__wchar_t_cat_45_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    CWE665_Improper_Initialization__wchar_t_cat_45_badData = data;
    badSink();
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
    CWE665_Improper_Initialization__wchar_t_cat_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
