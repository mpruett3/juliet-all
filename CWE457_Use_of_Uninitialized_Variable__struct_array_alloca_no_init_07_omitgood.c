/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_07.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c_array.label.xml
Template File: sources-sinks-07.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_07_bad()
{
    twoIntsStruct * data;
    data = (twoIntsStruct *)ALLOCA(10*sizeof(twoIntsStruct));
    if(staticFive==5)
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(staticFive==5)
    {
        /* POTENTIAL FLAW: Use data without initializing it */
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].intOne);
                printIntLine(data[i].intTwo);
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
    CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif