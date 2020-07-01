/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__listen_socket_sleep_22b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP Sleep
#else
#include <unistd.h>
#define SLEEP usleep
#endif

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE400_Resource_Exhaustion__listen_socket_sleep_22_badGlobal;

void CWE400_Resource_Exhaustion__listen_socket_sleep_22_badSink(int count)
{
    if(CWE400_Resource_Exhaustion__listen_socket_sleep_22_badGlobal)
    {
        /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
        SLEEP(count);
        printLine("Sleep time possibly too long");
    }
}

#endif /* OMITBAD */

