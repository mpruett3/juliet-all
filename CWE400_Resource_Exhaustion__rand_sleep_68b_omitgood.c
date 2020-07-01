/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_sleep_68b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

extern int CWE400_Resource_Exhaustion__rand_sleep_68_badData;
extern int CWE400_Resource_Exhaustion__rand_sleep_68_goodG2BData;
extern int CWE400_Resource_Exhaustion__rand_sleep_68_goodB2GData;

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__rand_sleep_68b_badSink()
{
    int count = CWE400_Resource_Exhaustion__rand_sleep_68_badData;
    /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
    SLEEP(count);
    printLine("Sleep time possibly too long");
}

#endif /* OMITBAD */

