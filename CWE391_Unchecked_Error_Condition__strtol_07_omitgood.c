/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__strtol_07.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: strtol
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if strtol() failed
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

#include <errno.h>

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

#ifndef OMITBAD

void CWE391_Unchecked_Error_Condition__strtol_07_bad()
{
    if(staticFive==5)
    {
        {
            long longNumber;
            longNumber = strtol("0xfffffffff", NULL, 0);
            /* FLAW: Do not check to see if strtol() failed */
            printf("%li\n", longNumber);
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
    CWE391_Unchecked_Error_Condition__strtol_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif