/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_sleep_67b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE400_Resource_Exhaustion__fscanf_sleep_67_structType
{
    int structFirst;
} CWE400_Resource_Exhaustion__fscanf_sleep_67_structType;

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__fscanf_sleep_67b_badSink(CWE400_Resource_Exhaustion__fscanf_sleep_67_structType myStruct)
{
    int count = myStruct.structFirst;
    /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
    SLEEP(count);
    printLine("Sleep time possibly too long");
}

#endif /* OMITBAD */
