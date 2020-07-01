/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__struct_alloca_use_03.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: alloca_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from alloca without initialization
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE758_Undefined_Behavior__struct_alloca_use_03_bad()
{
    if(5==5)
    {
        {
            twoIntsStruct * pointer = (twoIntsStruct *)ALLOCA(sizeof(twoIntsStruct));
            twoIntsStruct data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printIntLine(data.intOne);
            printIntLine(data.intTwo);
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
    CWE758_Undefined_Behavior__struct_alloca_use_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif