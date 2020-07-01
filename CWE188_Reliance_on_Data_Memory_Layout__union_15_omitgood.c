/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE188_Reliance_on_Data_Memory_Layout__union_15.c
Label Definition File: CWE188_Reliance_on_Data_Memory_Layout.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 188 Reliance on Data Memory Layout
 * Sinks: union
 *    GoodSink: Use mechanisms that are not dependent upon size, alignment/packing, or byte order to accomplish equivalent functionality
 *    BadSink : Modify a union member by relying on the byte-order, size, alignment/packing of struct and union fields
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE188_Reliance_on_Data_Memory_Layout__union_15_bad()
{
    switch(6)
    {
    case 6:
    {
        union
        {
            struct
            {
                char charFirst, charSecond, charThird, charFourth;
            } structChars;
            long longNumber;
        } unionStructLong;
        unionStructLong.longNumber = 0x10203040;
        /* FLAW: this operation depends on the byte-order, size, alignment/packing of
         * struct and union fields */
        unionStructLong.structChars.charFourth |= 0x80; /* "set the MSB" */
        printIntLine(unionStructLong.longNumber);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
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
    CWE188_Reliance_on_Data_Memory_Layout__union_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
