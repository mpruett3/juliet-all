/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_calloc_65b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__int_calloc_65b_badSink(int * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */
