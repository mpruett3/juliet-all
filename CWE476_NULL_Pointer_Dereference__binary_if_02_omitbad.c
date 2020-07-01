/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__binary_if_02.c
Label Definition File: CWE476_NULL_Pointer_Dereference.pointflaw.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * Sinks: binary_if
 *    GoodSink: Do not check for NULL after the pointer has been dereferenced
 *    BadSink : Check for NULL after a pointer has already been dereferenced
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
            twoIntsStruct *twoIntsStructPointer = NULL;
            /* FIX: Use && in the if statement so that if the left side of the expression fails then
             * the right side will not be evaluated */
            if ((twoIntsStructPointer != NULL) && (twoIntsStructPointer->intOne == 5))
            {
                printLine("intOne == 5");
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
            twoIntsStruct *twoIntsStructPointer = NULL;
            /* FIX: Use && in the if statement so that if the left side of the expression fails then
             * the right side will not be evaluated */
            if ((twoIntsStructPointer != NULL) && (twoIntsStructPointer->intOne == 5))
            {
                printLine("intOne == 5");
            }
        }
    }
}

void CWE476_NULL_Pointer_Dereference__binary_if_02_good()
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
    CWE476_NULL_Pointer_Dereference__binary_if_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif