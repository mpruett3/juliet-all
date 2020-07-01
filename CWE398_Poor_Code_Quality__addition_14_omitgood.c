/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__addition_14.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: addition
 *    GoodSink: Adding two ints and storing the result
 *    BadSink : Adding two ints but not storing the result has no effect
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE398_Poor_Code_Quality__addition_14_bad()
{
    if(globalFive==5)
    {
        {
            int intOne = 1, intTwo = 1, intSum = 0;
            printIntLine(intSum);
            /* FLAW: the statement has no effect */
            intOne + intTwo; /* This generates a compiler warning, but we expect it to */
            printIntLine(intSum);
        }
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
    CWE398_Poor_Code_Quality__addition_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
