/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_for_loop_68b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(count) + 2)

extern int CWE400_Resource_Exhaustion__fgets_for_loop_68_badData;
extern int CWE400_Resource_Exhaustion__fgets_for_loop_68_goodG2BData;
extern int CWE400_Resource_Exhaustion__fgets_for_loop_68_goodB2GData;

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__fgets_for_loop_68b_badSink()
{
    int count = CWE400_Resource_Exhaustion__fgets_for_loop_68_badData;
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

