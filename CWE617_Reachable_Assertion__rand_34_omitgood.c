/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__rand_34.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Number greater than ASSERT_VALUE
 * Sinks:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

typedef union
{
    int unionFirst;
    int unionSecond;
} CWE617_Reachable_Assertion__rand_34_unionType;

#ifndef OMITBAD

void CWE617_Reachable_Assertion__rand_34_bad()
{
    int data;
    CWE617_Reachable_Assertion__rand_34_unionType myUnion;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        /* POTENTIAL FLAW: this assertion could trigger if n <= ASSERT_VALUE */
        assert(data > ASSERT_VALUE);
    }
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
    CWE617_Reachable_Assertion__rand_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
