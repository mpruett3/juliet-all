/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_listen_socket_divide_22b.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Non-zero
 * Sinks: divide
 *    GoodSink: Check for zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE369_Divide_by_Zero__int_listen_socket_divide_22_badGlobal;

void CWE369_Divide_by_Zero__int_listen_socket_divide_22_badSink(int data)
{
    if(CWE369_Divide_by_Zero__int_listen_socket_divide_22_badGlobal)
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        printIntLine(100 / data);
    }
}

#endif /* OMITBAD */
