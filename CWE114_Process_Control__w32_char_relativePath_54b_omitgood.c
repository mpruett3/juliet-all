/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_relativePath_54b.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: relativePath Hard code the relative pathname to the library
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE114_Process_Control__w32_char_relativePath_54c_badSink(char * data);

void CWE114_Process_Control__w32_char_relativePath_54b_badSink(char * data)
{
    CWE114_Process_Control__w32_char_relativePath_54c_badSink(data);
}

#endif /* OMITBAD */
