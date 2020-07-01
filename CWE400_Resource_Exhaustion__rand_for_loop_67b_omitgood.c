/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_for_loop_67b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE400_Resource_Exhaustion__rand_for_loop_67_structType
{
    int structFirst;
} CWE400_Resource_Exhaustion__rand_for_loop_67_structType;

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__rand_for_loop_67b_badSink(CWE400_Resource_Exhaustion__rand_for_loop_67_structType myStruct)
{
    int count = myStruct.structFirst;
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

