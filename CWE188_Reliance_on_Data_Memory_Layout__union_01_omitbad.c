/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE188_Reliance_on_Data_Memory_Layout__union_01.c
Label Definition File: CWE188_Reliance_on_Data_Memory_Layout.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 188 Reliance on Data Memory Layout
 * Sinks: union
 *    GoodSink: Use mechanisms that are not dependent upon size, alignment/packing, or byte order to accomplish equivalent functionality
 *    BadSink : Modify a union member by relying on the byte-order, size, alignment/packing of struct and union fields
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

static void good1()
{
    {
        long longNumber;
        longNumber = 0x10203040;
        /* FIX: Use mechanisms that are not dependent upon size, alignment/packing,
         * or byte order to accomplish equivalent functionality
         *
         * Technically this 'fix' here still depends on twos-complement hardware,
         * but everything nowadays is twos-complement
         */
        longNumber |= LONG_MIN;
        printIntLine(longNumber);
    }
}

void CWE188_Reliance_on_Data_Memory_Layout__union_01_good()
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
    CWE188_Reliance_on_Data_Memory_Layout__union_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
