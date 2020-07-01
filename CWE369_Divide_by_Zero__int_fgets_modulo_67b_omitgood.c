/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_fgets_modulo_67b.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

typedef struct _CWE369_Divide_by_Zero__int_fgets_modulo_67_structType
{
    int structFirst;
} CWE369_Divide_by_Zero__int_fgets_modulo_67_structType;

#ifndef OMITBAD

void CWE369_Divide_by_Zero__int_fgets_modulo_67b_badSink(CWE369_Divide_by_Zero__int_fgets_modulo_67_structType myStruct)
{
    int data = myStruct.structFirst;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}

#endif /* OMITBAD */

