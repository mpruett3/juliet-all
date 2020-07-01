/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int_realloc_22b.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE690_NULL_Deref_From_Return__int_realloc_22_badGlobal;

void CWE690_NULL_Deref_From_Return__int_realloc_22_badSink(int * data)
{
    if(CWE690_NULL_Deref_From_Return__int_realloc_22_badGlobal)
    {
        /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
        data[0] = 5;
        printIntLine(data[0]);
        free(data);
    }
}

#endif /* OMITBAD */
