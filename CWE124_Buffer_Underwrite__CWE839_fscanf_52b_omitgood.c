/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_fscanf_52b.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE124_Buffer_Underwrite__CWE839_fscanf_52c_badSink(int data);

void CWE124_Buffer_Underwrite__CWE839_fscanf_52b_badSink(int data)
{
    CWE124_Buffer_Underwrite__CWE839_fscanf_52c_badSink(data);
}

#endif /* OMITBAD */

