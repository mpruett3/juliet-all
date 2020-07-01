/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__double_array_declare_no_init_64b.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c_array.label.xml
Template File: sources-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__double_array_declare_no_init_64b_badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    double * * dataPtr = (double * *)dataVoidPtr;
    /* dereference dataPtr into data */
    double * data = (*dataPtr);
    /* POTENTIAL FLAW: Use data without initializing it */
    {
        int i;
        for(i=0; i<10; i++)
        {
            printDoubleLine(data[i]);
        }
    }
}

#endif /* OMITBAD */
