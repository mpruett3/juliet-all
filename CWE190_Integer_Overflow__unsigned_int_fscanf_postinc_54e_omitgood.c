/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fscanf_postinc_54e.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-54e.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_fscanf_postinc_54e_badSink(unsigned int data)
{
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}

#endif /* OMITBAD */
