/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE364_Signal_Handler_Race_Condition__basic_10.c
Label Definition File: CWE364_Signal_Handler_Race_Condition__basic.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 364 Signal Handler Race Condition
 * Sinks:
 *    GoodSink: Disable the signal handler while performing non-atomic operations
 *    BadSink : Do not disable the signal handler while performing non-atomic operations
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <signal.h>

typedef struct _structSigAtomic
{
    sig_atomic_t val;
}   structSigAtomic;

structSigAtomic *CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad = NULL;
structSigAtomic *CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicGood = NULL;

static void helperBad(int sig)
{
    if (CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad != NULL)
    {
        CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad->val = 2;
    }
}

static void helperGood(int sig)
{
    if (CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicGood != NULL)
    {
        CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicGood->val = 2;
    }
}

#ifndef OMITBAD

void CWE364_Signal_Handler_Race_Condition__basic_10_bad()
{
    if(globalTrue)
    {
        {
            structSigAtomic *gStructSigAtomic = NULL;
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad);
                CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad = NULL;
            }
            gStructSigAtomic = (structSigAtomic*)malloc(sizeof(structSigAtomic));
            if (gStructSigAtomic == NULL) {exit(-1);}
            CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad = gStructSigAtomic;
            CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad->val = 1;
            /* Assign CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad BEFORE
             * calling 'signal', because pointer types are not (according to spec), atomic
             * with respect to signals.
             *
             * In practice they are on most (all?) POSIX-y computers, but thems the
             * rules
             */
            signal(SIGINT, helperBad);
            /* FLAW: This test, free, and set operation is not atomic, so if signal
             * delivery occurs (for example) between the free and setting to NULL,
             * the signal handler could corrupt the heap, cause an access violation,
             * etc
             *
             * Technically, "CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad = 0" is not atomic on certain theoretical computer
             * systems that don't actually exist, but this should trigger on
             * theoretical as well as actual computer systems.
             */
            if (CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad);
                CWE364_Signal_Handler_Race_Condition__basic_10StructSigAtomicBad = NULL;
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
    CWE364_Signal_Handler_Race_Condition__basic_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
