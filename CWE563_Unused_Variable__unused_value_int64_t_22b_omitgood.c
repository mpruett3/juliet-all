/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_int64_t_22b.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE563_Unused_Variable__unused_value_int64_t_22_badGlobal;

void CWE563_Unused_Variable__unused_value_int64_t_22_badSink(int64_t data)
{
    if(CWE563_Unused_Variable__unused_value_int64_t_22_badGlobal)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 10LL;
        printLongLongLine(data);
    }
}

#endif /* OMITBAD */

