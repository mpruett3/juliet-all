/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_long_22a.c
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
int CWE563_Unused_Variable__unused_init_variable_long_22_badGlobal = 0;

void CWE563_Unused_Variable__unused_init_variable_long_22_badSink(long data);

void CWE563_Unused_Variable__unused_init_variable_long_22_bad()
{
    long data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5L;
    CWE563_Unused_Variable__unused_init_variable_long_22_badGlobal = 1; /* true */
    CWE563_Unused_Variable__unused_init_variable_long_22_badSink(data);
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
    CWE563_Unused_Variable__unused_init_variable_long_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif