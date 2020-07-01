/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fixed_22b.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fixed Fixed value less than the assert value
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE617_Reachable_Assertion__fixed_22_badGlobal;

int CWE617_Reachable_Assertion__fixed_22_badSource(int data)
{
    if(CWE617_Reachable_Assertion__fixed_22_badGlobal)
    {
        /* FLAW: Use a value less than the assert value */
        data = ASSERT_VALUE-1;
    }
    return data;
}

#endif /* OMITBAD */

