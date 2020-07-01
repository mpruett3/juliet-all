/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE667_Improper_Locking__basic_13.c
Label Definition File: CWE667_Improper_Locking__basic.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 667 Improper Locking
 * Sinks:
 *    GoodSink: Acquire a lock before releasing it
 *    BadSink : Release the lock before acquiring it
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include "std_thread.h"

#ifndef OMITBAD

void CWE667_Improper_Locking__basic_13_bad()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            static stdThreadLock badLock = NULL;
            printLine("Creating lock...");
            if (!stdThreadLockCreate(&badLock))
            {
                printLine("Could not create lock");
                exit(1);
            }
            printLine("Acquiring lock...");
            stdThreadLockAcquire(badLock);
            /* FLAW: Do not release the lock */
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
    CWE667_Improper_Locking__basic_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
