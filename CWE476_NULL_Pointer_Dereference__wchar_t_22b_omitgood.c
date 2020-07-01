/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__wchar_t_22b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE476_NULL_Pointer_Dereference__wchar_t_22_badGlobal;

void CWE476_NULL_Pointer_Dereference__wchar_t_22_badSink(wchar_t * data)
{
    if(CWE476_NULL_Pointer_Dereference__wchar_t_22_badGlobal)
    {
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        /* printWLine() checks for NULL, so we cannot use it here */
        printWcharLine(data[0]);
    }
}

#endif /* OMITBAD */

