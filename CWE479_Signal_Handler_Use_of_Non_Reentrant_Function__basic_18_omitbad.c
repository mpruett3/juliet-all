/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_18.c
Label Definition File: CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 479 Signal Handler Use of Non-Reentrant Function
 * Sinks:
 *    GoodSink: Don't call a function from within the signal handler
 *    BadSink : malloc() and free() inside a signal handler
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <signal.h>

static void helperBad(int sig)
{
    /* FLAW: malloc and free are not re-entrant */
    /* Used to be printf in here, but we are trying to avoid that.
     * Detecting that printLine ultimately calls printf requires inter-
     * procedural analysis, so we cannot do that either.  So instead,
     * do something very contrived with malloc/free
     */
    void *voidPointer = malloc(10);
    if (voidPointer == NULL) {exit(-1);}
    free(voidPointer);
}

static volatile sig_atomic_t volatileSigAtomic = 0;

static void helperGood(int sig)
{
    /* FIX: Basically, "don't do anything" in signal handlers.  Set a flag at
     * best, and if you have to call a function, ensure it's a re-entrant
     * asynchronous-safe one that doesn't eat up a lot of time
     */
    volatileSigAtomic = sig;
}


#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    signal(SIGINT, helperGood);
}

void CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_18_good()
{
    good1();
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
    CWE479_Signal_Handler_Use_of_Non_Reentrant_Function__basic_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif