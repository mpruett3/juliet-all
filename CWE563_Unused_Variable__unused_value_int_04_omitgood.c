/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_int_04.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-04.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_value_int_04_bad()
{
    int data;
    if(STATIC_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 5;
    }
    if(STATIC_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 10;
        printIntLine(data);
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
    CWE563_Unused_Variable__unused_value_int_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif