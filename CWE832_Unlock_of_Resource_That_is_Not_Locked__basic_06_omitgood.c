/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_06.c
Label Definition File: CWE832_Unlock_of_Resource_That_is_Not_Locked__basic.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 832 Unlock Of Resource That Is Not Locked
 * Sinks:
 *    GoodSink: Acquire a lock before releasing it
 *    BadSink : Release the lock before acquiring it
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include "std_thread.h"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_06_bad()
{
    if(STATIC_CONST_FIVE==5)
    {
        {
            static stdThreadLock badLock = NULL;
            printLine("Creating lock...");
            if (!stdThreadLockCreate(&badLock))
            {
                printLine("Could not create lock");
                exit(1);
            }
            /* FLAW: Release the lock before acquiring it */
            printLine("Releasing lock...");
            stdThreadLockRelease(badLock);
            printLine("Destroying lock...");
            stdThreadLockDestroy(badLock);
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
    CWE832_Unlock_of_Resource_That_is_Not_Locked__basic_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
