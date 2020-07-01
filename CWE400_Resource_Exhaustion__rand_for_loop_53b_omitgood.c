/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_for_loop_53b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__rand_for_loop_53c_badSink(int count);

void CWE400_Resource_Exhaustion__rand_for_loop_53b_badSink(int count)
{
    CWE400_Resource_Exhaustion__rand_for_loop_53c_badSink(count);
}

#endif /* OMITBAD */
