/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_for_loop_22a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
int CWE400_Resource_Exhaustion__fscanf_for_loop_22_badGlobal = 0;

void CWE400_Resource_Exhaustion__fscanf_for_loop_22_badSink(int count);

void CWE400_Resource_Exhaustion__fscanf_for_loop_22_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_badGlobal = 1; /* true */
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_badSink(count);
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
    CWE400_Resource_Exhaustion__fscanf_for_loop_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
