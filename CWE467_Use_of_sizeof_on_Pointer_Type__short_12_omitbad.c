/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__short_12.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * Sinks: short
 *    GoodSink: Use sizeof() the data type
 *    BadSink : Use sizeof() the pointer and not the data type
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            short * goodShort = NULL;
            /* FIX: Using sizeof the data type in malloc() */
            goodShort = (short *)malloc(sizeof(*goodShort));
            if (goodShort == NULL) {exit(-1);}
            *goodShort = 6;
            printShortLine(*goodShort);
            free(goodShort);
        }
    }
    else
    {
        {
            short * goodShort = NULL;
            /* FIX: Using sizeof the data type in malloc() */
            goodShort = (short *)malloc(sizeof(*goodShort));
            if (goodShort == NULL) {exit(-1);}
            *goodShort = 6;
            printShortLine(*goodShort);
            free(goodShort);
        }
    }
}

void CWE467_Use_of_sizeof_on_Pointer_Type__short_12_good()
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
    CWE467_Use_of_sizeof_on_Pointer_Type__short_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
