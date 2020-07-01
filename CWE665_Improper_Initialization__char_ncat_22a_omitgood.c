/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_22a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE665_Improper_Initialization__char_ncat_22_badGlobal = 0;

char * CWE665_Improper_Initialization__char_ncat_22_badSource(char * data);

void CWE665_Improper_Initialization__char_ncat_22_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    CWE665_Improper_Initialization__char_ncat_22_badGlobal = 1; /* true */
    data = CWE665_Improper_Initialization__char_ncat_22_badSource(data);
    {
        size_t sourceLen;
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        sourceLen = strlen(source);
        /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, source, sourceLen);
        printLine(data);
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
    CWE665_Improper_Initialization__char_ncat_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
