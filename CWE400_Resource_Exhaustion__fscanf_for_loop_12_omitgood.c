/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_for_loop_12.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__fscanf_for_loop_12_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Read count from the console using fscanf() */
        fscanf(stdin, "%d", &count);
    }
    else
    {
        /* FIX: Use a relatively small number */
        count = 20;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            size_t i = 0;
            /* POTENTIAL FLAW: For loop using count as the loop variant and no validation */
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
    }
    else
    {
        {
            size_t i = 0;
            /* FIX: Validate count before using it as the for loop variant */
            if (count > 0 && count <= 20)
            {
                for (i = 0; i < (size_t)count; i++)
                {
                    printLine("Hello");
                }
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
    CWE400_Resource_Exhaustion__fscanf_for_loop_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif