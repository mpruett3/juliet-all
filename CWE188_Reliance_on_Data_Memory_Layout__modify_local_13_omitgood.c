/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE188_Reliance_on_Data_Memory_Layout__modify_local_13.c
Label Definition File: CWE188_Reliance_on_Data_Memory_Layout.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 188 Reliance on Data Memory Layout
 * Sinks: modify_local
 *    GoodSink: Modify the second field of the struct using the field name
 *    BadSink : Attempt to modify second field in struct, assuming the first field is an int
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE188_Reliance_on_Data_Memory_Layout__modify_local_13_bad()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            struct
            {
                char charFirst;
                int intSecond;
            } structCharInt;
            char *charPtr;
            structCharInt.charFirst = 1;
            charPtr = &structCharInt.charFirst;
            /* FLAW: Attempt to modify intSecond assuming intSecond comes after charFirst and
             * is aligned on an int-boundary after charFirst */
            *(int*)(charPtr + sizeof(int)) = 5;
            printIntLine(structCharInt.charFirst);
            printIntLine(structCharInt.intSecond);
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
    CWE188_Reliance_on_Data_Memory_Layout__modify_local_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif