/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_rand_modulo_11.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-11.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_by_Zero__int_rand_modulo_11_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 % data);
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
    CWE369_Divide_by_Zero__int_rand_modulo_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif