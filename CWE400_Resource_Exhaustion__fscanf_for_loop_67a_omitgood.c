/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_for_loop_67a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE400_Resource_Exhaustion__fscanf_for_loop_67_structType
{
    int structFirst;
} CWE400_Resource_Exhaustion__fscanf_for_loop_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__fscanf_for_loop_67b_badSink(CWE400_Resource_Exhaustion__fscanf_for_loop_67_structType myStruct);

void CWE400_Resource_Exhaustion__fscanf_for_loop_67_bad()
{
    int count;
    CWE400_Resource_Exhaustion__fscanf_for_loop_67_structType myStruct;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    myStruct.structFirst = count;
    CWE400_Resource_Exhaustion__fscanf_for_loop_67b_badSink(myStruct);
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
    CWE400_Resource_Exhaustion__fscanf_for_loop_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
