/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_sleep_54d.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
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


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__rand_sleep_54e_goodG2BSink(int count);

void CWE400_Resource_Exhaustion__rand_sleep_54d_goodG2BSink(int count)
{
    CWE400_Resource_Exhaustion__rand_sleep_54e_goodG2BSink(count);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__rand_sleep_54e_goodB2GSink(int count);

void CWE400_Resource_Exhaustion__rand_sleep_54d_goodB2GSink(int count)
{
    CWE400_Resource_Exhaustion__rand_sleep_54e_goodB2GSink(count);
}

#endif /* OMITGOOD */