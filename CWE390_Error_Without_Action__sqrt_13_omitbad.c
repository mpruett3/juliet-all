/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__sqrt_13.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: sqrt
 *    GoodSink: Check to see if sqrt() failed and handle errors properly
 *    BadSink : Check to see if sqrt() failed, but fail to handle errors
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <math.h>
#include <errno.h>


#ifndef OMITGOOD

/* good1() uses if(GLOBAL_CONST_FIVE!=5) instead of if(GLOBAL_CONST_FIVE==5) */
static void good1()
{
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            double doubleNumber;
            errno = 0; /* set errno to zero before calling sqrt(), which can change its value */
            doubleNumber = (double)sqrt((double)-1);
            /* FIX: Check errno to see if sqrt() failed and handle errors properly */
            if (errno == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(doubleNumber);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            double doubleNumber;
            errno = 0; /* set errno to zero before calling sqrt(), which can change its value */
            doubleNumber = (double)sqrt((double)-1);
            /* FIX: Check errno to see if sqrt() failed and handle errors properly */
            if (errno == EDOM)
            {
                printLine("sqrt() failed");
                exit(1);
            }
            printDoubleLine(doubleNumber);
        }
    }
}

void CWE390_Error_Without_Action__sqrt_13_good()
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
    CWE390_Error_Without_Action__sqrt_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif