/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_file_61b.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: file Read input from a file
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <windows.h>


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
char * CWE114_Process_Control__w32_char_file_61b_goodG2BSource(char * data)
{
    /* FIX: Specify the full pathname for the library */
    strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    return data;
}

#endif /* OMITGOOD */
