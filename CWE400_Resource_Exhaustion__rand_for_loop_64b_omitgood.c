/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_for_loop_64b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__rand_for_loop_64b_badSink(void * countVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * countPtr = (int *)countVoidPtr;
    /* dereference countPtr into count */
    int count = (*countPtr);
    {
        size_t i = 0;
        /* POTENTIAL FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

#endif /* OMITBAD */

