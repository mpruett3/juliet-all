/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__strtol_11.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: strtol
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if strtol() failed
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#ifndef OMITBAD

void CWE391_Unchecked_Error_Condition__strtol_11_bad()
{
    if(globalReturnsTrue())
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
    CWE391_Unchecked_Error_Condition__strtol_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
