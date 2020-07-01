/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fscanf_05.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-05.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

/* The two variables below are not defined as "const", but are never
 * assigned any other value, so a tool should be able to identify that
 * reads of these will always return their initialized values.
 */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE617_Reachable_Assertion__fscanf_05_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(staticTrue)
    {
        /* POTENTIAL FLAW: Read data from the console using fscanf() */
        fscanf(stdin, "%d", &data);
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
    CWE617_Reachable_Assertion__fscanf_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
