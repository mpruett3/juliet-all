/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__binary_if_03.c
Label Definition File: CWE476_NULL_Pointer_Dereference.pointflaw.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * Sinks: binary_if
 *    GoodSink: Do not check for NULL after the pointer has been dereferenced
 *    BadSink : Check for NULL after a pointer has already been dereferenced
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__binary_if_03_bad()
{
    if(5==5)
    {
        {
            twoIntsStruct *twoIntsStructPointer = NULL;
            /* FLAW: Using a single & in the if statement will cause both sides of the expression to be evaluated
             * thus causing a NPD */
            if ((twoIntsStructPointer != NULL) & (twoIntsStructPointer->intOne == 5))
            {
                printLine("intOne == 5");
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
    CWE476_NULL_Pointer_Dereference__binary_if_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
