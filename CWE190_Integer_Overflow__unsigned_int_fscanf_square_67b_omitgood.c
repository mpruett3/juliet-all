/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_fscanf_square_67b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

typedef struct _CWE190_Integer_Overflow__unsigned_int_fscanf_square_67_structType
{
    unsigned int structFirst;
} CWE190_Integer_Overflow__unsigned_int_fscanf_square_67_structType;

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_fscanf_square_67b_badSink(CWE190_Integer_Overflow__unsigned_int_fscanf_square_67_structType myStruct)
{
    unsigned int data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: if (data*data) > UINT_MAX, this will overflow */
        unsigned int result = data * data;
        printUnsignedLine(result);
    }
}

#endif /* OMITBAD */
