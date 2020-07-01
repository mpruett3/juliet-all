/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncpy_54d.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: ncpy
 *    BadSink : Copy data to string using strncpy
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncpy_54e_badSink(char * data);

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncpy_54d_badSink(char * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncpy_54e_badSink(data);
}

#endif /* OMITBAD */
