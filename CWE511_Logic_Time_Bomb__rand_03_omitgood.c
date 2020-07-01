/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE511_Logic_Time_Bomb__rand_03.c
Label Definition File: CWE511_Logic_Time_Bomb.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 511 Logic Time Bomb
 * Sinks: rand
 *    GoodSink: If specific random number generated, do something harmless
 *    BadSink : If specific random number generated, do something bad
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define UNLINK _unlink
#else
#include <unistd.h>
#define UNLINK unlink
#endif

#define NUM_CHECK 20000

#ifndef OMITBAD

void CWE511_Logic_Time_Bomb__rand_03_bad()
{
    if(5==5)
    {
        srand((unsigned)time(NULL));
        /* FLAW: If a certain number, delete a file */
        if (rand() == NUM_CHECK)
        {
            UNLINK("important_file.txt");
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
    CWE511_Logic_Time_Bomb__rand_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
