/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__deref_after_check_02.c
Label Definition File: CWE476_NULL_Pointer_Dereference.pointflaw.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * Sinks: deref_after_check
 *    GoodSink: Do not dereference a pointer if it is NULL
 *    BadSink : Dereference a pointer after checking to see if it is NULL
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            /* FIX: Check for NULL and do not dereference the pointer if it is NULL */
            int *intPointer = NULL;
            if (intPointer == NULL)
            {
                printLine("pointer is NULL");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
            /* FIX: Check for NULL and do not dereference the pointer if it is NULL */
            int *intPointer = NULL;
            if (intPointer == NULL)
            {
                printLine("pointer is NULL");
            }
        }
    }
}

void CWE476_NULL_Pointer_Dereference__deref_after_check_02_good()
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
    CWE476_NULL_Pointer_Dereference__deref_after_check_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif