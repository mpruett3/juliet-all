/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_zero_modulo_09.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE369_Divide_by_Zero__int_zero_modulo_09_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Set data to zero */
        data = 0;
    }
    if(GLOBAL_CONST_TRUE)
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
    CWE369_Divide_by_Zero__int_zero_modulo_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
