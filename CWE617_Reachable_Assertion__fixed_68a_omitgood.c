/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fixed_68a.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fixed Fixed value less than the assert value
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

int CWE617_Reachable_Assertion__fixed_68_badData;
int CWE617_Reachable_Assertion__fixed_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE617_Reachable_Assertion__fixed_68b_badSink();

void CWE617_Reachable_Assertion__fixed_68_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a value less than the assert value */
    data = ASSERT_VALUE-1;
    CWE617_Reachable_Assertion__fixed_68_badData = data;
    CWE617_Reachable_Assertion__fixed_68b_badSink();
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
    CWE617_Reachable_Assertion__fixed_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
