/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE481_Assigning_Instead_of_Comparing__basic_13.c
Label Definition File: CWE481_Assigning_Instead_of_Comparing__basic.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 481 Assigning Instead of Comparing
 * Sinks:
 *    GoodSink: Comparing
 *    BadSink : Assigning instead of comparing
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE481_Assigning_Instead_of_Comparing__basic_13_bad()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            int intRand = rand();
            /* FLAW: should be == and INCIDENTIAL CWE 571 Expression Is Always True */
            if(intRand = 5)
            {
                printLine("i was 5");
            }
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
    CWE481_Assigning_Instead_of_Comparing__basic_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
