/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoIntsStruct_realloc_53c.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__twoIntsStruct_realloc_53d_badSink(twoIntsStruct * data);

void CWE401_Memory_Leak__twoIntsStruct_realloc_53c_badSink(twoIntsStruct * data)
{
    CWE401_Memory_Leak__twoIntsStruct_realloc_53d_badSink(data);
}

#endif /* OMITBAD */

