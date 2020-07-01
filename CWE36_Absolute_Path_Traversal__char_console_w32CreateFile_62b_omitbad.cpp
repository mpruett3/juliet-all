/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_console_w32CreateFile_62b.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: console Read input from the console
 * GoodSource: Full path and file name
 * Sinks: w32CreateFile
 *    BadSink : Open the file named in data using CreateFile()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#include <windows.h>

namespace CWE36_Absolute_Path_Traversal__char_console_w32CreateFile_62
{


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(char * &data)
{
#ifdef _WIN32
    /* FIX: Use a fixed, full path and file name */
    strcat(data, "c:\\temp\\file.txt");
#else
    /* FIX: Use a fixed, full path and file name */
    strcat(data, "/tmp/file.txt");
#endif
}

#endif /* OMITGOOD */

} /* close namespace */
