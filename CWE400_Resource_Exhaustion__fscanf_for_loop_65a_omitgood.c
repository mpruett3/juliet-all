/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_for_loop_65a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__fscanf_for_loop_65b_badSink(int count);

void CWE400_Resource_Exhaustion__fscanf_for_loop_65_bad()
{
    int count;
    /* define a function pointer */
    void (*funcPtr) (int) = CWE400_Resource_Exhaustion__fscanf_for_loop_65b_badSink;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    /* use the function pointer */
    funcPtr(count);
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
    CWE400_Resource_Exhaustion__fscanf_for_loop_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
