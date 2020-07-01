/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int64_t_calloc_22b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE401_Memory_Leak__int64_t_calloc_22_badGlobal;

void CWE401_Memory_Leak__int64_t_calloc_22_badSink(int64_t * data)
{
    if(CWE401_Memory_Leak__int64_t_calloc_22_badGlobal)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

