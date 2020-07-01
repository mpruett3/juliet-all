/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE364_Signal_Handler_Race_Condition__basic_11.c
Label Definition File: CWE364_Signal_Handler_Race_Condition__basic.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 364 Signal Handler Race Condition
 * Sinks:
 *    GoodSink: Disable the signal handler while performing non-atomic operations
 *    BadSink : Do not disable the signal handler while performing non-atomic operations
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <signal.h>

typedef struct _structSigAtomic
{
    sig_atomic_t val;
}   structSigAtomic;

structSigAtomic *CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicBad = NULL;
structSigAtomic *CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood = NULL;

static void helperBad(int sig)
{
    if (CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicBad != NULL)
    {
        CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicBad->val = 2;
    }
}

static void helperGood(int sig)
{
    if (CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood != NULL)
    {
        CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood->val = 2;
    }
}


#ifndef OMITGOOD

/* good1() uses if(globalReturnsFalse()) instead of if(globalReturnsTrue()) */
static void good1()
{
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            structSigAtomic *gStructSigAtomic = NULL;
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood);
                CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood = 0;
            }
            gStructSigAtomic = (structSigAtomic*)malloc(sizeof(structSigAtomic));
            if (gStructSigAtomic == NULL) {exit(-1);}
            CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood = gStructSigAtomic;
            CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood->val = 1;
            /* Assign CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood BEFORE
             * calling 'signal', because pointer types are not (according to spec), atomic
             * with respect to signals.
             *
             * In practice they are on most (all?) POSIX-y computers, but thems the
             * rules
             */
            signal(SIGINT, helperGood);
            /* FIX: In this instance, the fix is to temporarily disable the signal
             * handler while performing non-atomic operations.  Another way would
             * be to use sigprocmask or sigvec, or to restructure the signal handler
             * to operate in a safe manner.
             */
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood);
                CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood = NULL;
            }
            signal(SIGINT, helperGood);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalReturnsTrue())
    {
        {
            structSigAtomic *gStructSigAtomic = NULL;
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood);
                CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood = 0;
            }
            gStructSigAtomic = (structSigAtomic*)malloc(sizeof(structSigAtomic));
            if (gStructSigAtomic == NULL) {exit(-1);}
            CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood = gStructSigAtomic;
            CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood->val = 1;
            /* Assign CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood BEFORE
             * calling 'signal', because pointer types are not (according to spec), atomic
             * with respect to signals.
             *
             * In practice they are on most (all?) POSIX-y computers, but thems the
             * rules
             */
            signal(SIGINT, helperGood);
            /* FIX: In this instance, the fix is to temporarily disable the signal
             * handler while performing non-atomic operations.  Another way would
             * be to use sigprocmask or sigvec, or to restructure the signal handler
             * to operate in a safe manner.
             */
            signal(SIGINT, SIG_DFL);
            if (CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood != NULL)
            {
                free(CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood);
                CWE364_Signal_Handler_Race_Condition__basic_11StructSigAtomicGood = NULL;
            }
            signal(SIGINT, helperGood);
        }
    }
}

void CWE364_Signal_Handler_Race_Condition__basic_11_good()
{
    good1();
    good2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE364_Signal_Handler_Race_Condition__basic_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif