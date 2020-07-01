/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_wchar_t_11.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-11.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_value_wchar_t_11_bad()
{
    wchar_t data;
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = L'W';
    }
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = L'Z';
        printf("%02lx\n", data);
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
    CWE563_Unused_Variable__unused_value_wchar_t_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif