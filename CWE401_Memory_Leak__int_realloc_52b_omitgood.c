/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_realloc_52b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__int_realloc_52c_badSink(int * data);

void CWE401_Memory_Leak__int_realloc_52b_badSink(int * data)
{
    CWE401_Memory_Leak__int_realloc_52c_badSink(data);
}

#endif /* OMITBAD */

