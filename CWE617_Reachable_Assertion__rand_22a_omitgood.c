/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__rand_22a.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: rand Set data to result of rand(), which may be zero
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
int CWE617_Reachable_Assertion__rand_22_badGlobal = 0;

int CWE617_Reachable_Assertion__rand_22_badSource(int data);

void CWE617_Reachable_Assertion__rand_22_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE617_Reachable_Assertion__rand_22_badGlobal = 1; /* true */
    data = CWE617_Reachable_Assertion__rand_22_badSource(data);
    /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
    assert(data > ASSERT_VALUE);
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
    CWE617_Reachable_Assertion__rand_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
