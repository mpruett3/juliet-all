/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__wchar_t_68b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE476_NULL_Pointer_Dereference__wchar_t_68_badData;
extern wchar_t * CWE476_NULL_Pointer_Dereference__wchar_t_68_goodG2BData;
extern wchar_t * CWE476_NULL_Pointer_Dereference__wchar_t_68_goodB2GData;

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__wchar_t_68b_badSink()
{
    wchar_t * data = CWE476_NULL_Pointer_Dereference__wchar_t_68_badData;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printWLine() checks for NULL, so we cannot use it here */
    printWcharLine(data[0]);
}

#endif /* OMITBAD */

