/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__rand_04.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-04.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

/* The two variables below are declared "const", so a tool should
 * be able to identify that reads of these will always return their
 * initialized values.
 */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE617_Reachable_Assertion__rand_04_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(STATIC_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }
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
    CWE617_Reachable_Assertion__rand_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif