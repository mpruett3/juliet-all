/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_int_declare_loop_53b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: loop
 *    BadSink : Copy int array to data using a loop
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_declare_loop_53c_badSink(int * data);

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_declare_loop_53b_badSink(int * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int_declare_loop_53c_badSink(data);
}

#endif /* OMITBAD */
