/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__char_67b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE476_NULL_Pointer_Dereference__char_67_structType
{
    char * structFirst;
} CWE476_NULL_Pointer_Dereference__char_67_structType;

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__char_67b_badSink(CWE476_NULL_Pointer_Dereference__char_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printLine() checks for NULL, so we cannot use it here */
    printHexCharLine(data[0]);
}

#endif /* OMITBAD */
