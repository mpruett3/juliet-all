/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_file_fopen_52b.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-52b.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed file name
 * Sink: fopen
 *    BadSink : Open the file named in data using fopen()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH "/tmp/"
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifdef _WIN32
#define FOPEN fopen
#else
#define FOPEN fopen
#endif

namespace CWE23_Relative_Path_Traversal__char_file_fopen_52
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_c(char * data);

void goodG2BSink_b(char * data)
{
    goodG2BSink_c(data);
}

#endif /* OMITGOOD */

} /* close namespace */