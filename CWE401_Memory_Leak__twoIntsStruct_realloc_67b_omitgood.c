/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoIntsStruct_realloc_67b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE401_Memory_Leak__twoIntsStruct_realloc_67_structType
{
    twoIntsStruct * structFirst;
} CWE401_Memory_Leak__twoIntsStruct_realloc_67_structType;

#ifndef OMITBAD

void CWE401_Memory_Leak__twoIntsStruct_realloc_67b_badSink(CWE401_Memory_Leak__twoIntsStruct_realloc_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

