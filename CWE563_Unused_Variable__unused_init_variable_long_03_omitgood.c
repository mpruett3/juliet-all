/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_long_03.c
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-03.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_init_variable_long_03_bad()
{
    long data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5L;
    if(5==5)
    {
        /* FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
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
    CWE563_Unused_Variable__unused_init_variable_long_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
