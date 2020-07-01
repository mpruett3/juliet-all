/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_for_loop_22b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
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
extern int CWE400_Resource_Exhaustion__fgets_for_loop_22_badGlobal;

void CWE400_Resource_Exhaustion__fgets_for_loop_22_badSink(int count)
{
    if(CWE400_Resource_Exhaustion__fgets_for_loop_22_badGlobal)
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
}

#endif /* OMITBAD */

