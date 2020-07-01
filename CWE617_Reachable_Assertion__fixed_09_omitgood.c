/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fixed_09.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-09.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fixed Fixed value less than the assert value
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

#ifndef OMITBAD

void CWE617_Reachable_Assertion__fixed_09_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(GLOBAL_CONST_TRUE)
    {
        /* FLAW: Use a value less than the assert value */
        data = ASSERT_VALUE-1;
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
    CWE617_Reachable_Assertion__fixed_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
