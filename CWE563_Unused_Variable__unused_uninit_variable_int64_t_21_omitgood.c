/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_int64_t_21.c
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-21.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The static variable below is used to drive control flow in the sink function */
static int badStatic = 0;

static void badSink(int64_t data)
{
    if(badStatic)
    {
        /* FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

void CWE563_Unused_Variable__unused_uninit_variable_int64_t_21_bad()
{
    int64_t data;
    /* POTENTIAL FLAW: Do not initialize or use data */
    ; /* empty statement needed for some flow variants */
    badStatic = 1; /* true */
    badSink(data);
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
    CWE563_Unused_Variable__unused_uninit_variable_int64_t_21_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif