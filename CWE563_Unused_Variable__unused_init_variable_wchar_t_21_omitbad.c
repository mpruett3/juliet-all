/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_wchar_t_21.c
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-21.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* The static variables below are used to drive control flow in the sink functions. */
static int goodB2G1Static = 0;
static int goodB2G2Static = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
static void goodB2G1Sink(wchar_t data)
{
    if(goodB2G1Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use data */
        printWcharLine(data);
    }
}

static void goodB2G1()
{
    wchar_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
    goodB2G1Static = 0; /* false */
    goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
static void goodB2G2Sink(wchar_t data)
{
    if(goodB2G2Static)
    {
        /* FIX: Use data */
        printWcharLine(data);
    }
}

static void goodB2G2()
{
    wchar_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
    goodB2G2Static = 1; /* true */
    goodB2G2Sink(data);
}

void CWE563_Unused_Variable__unused_init_variable_wchar_t_21_good()
{
    goodB2G1();
    goodB2G2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE563_Unused_Variable__unused_init_variable_wchar_t_21_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif