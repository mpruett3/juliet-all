/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE338_Weak_PRNG__w32_17.c
Label Definition File: CWE338_Weak_PRNG__w32.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 338 Use of Cryptographically Weak PRNG
 * Sinks:
 *    GoodSink: Use CryptGenRandom() to generate a random number
 *    BadSink : Use rand() to generate a random number
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <wincrypt.h>
#pragma comment(lib, "advapi32.lib")

#ifndef OMITBAD

void CWE338_Weak_PRNG__w32_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            /* FLAW: Use of rand() as a PRNG */
            int data = rand();
            printIntLine(data);
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
    CWE338_Weak_PRNG__w32_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
