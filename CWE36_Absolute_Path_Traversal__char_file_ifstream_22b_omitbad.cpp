/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_file_ifstream_22b.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-22b.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Full path and file name
 * Sink: ifstream
 *    BadSink : Open the file named in data using ifstream::open()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

namespace CWE36_Absolute_Path_Traversal__char_file_ifstream_22
{


#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the source functions. Since they are in
a C++ namespace, they don't need globally unique names. */
extern int goodG2B1Global;
extern int goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the global variable to false instead of true */
char * goodG2B1Source(char * data)
{
    if(goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
#ifdef _WIN32
        /* FIX: Use a fixed, full path and file name */
        strcat(data, "c:\\temp\\file.txt");
#else
        /* FIX: Use a fixed, full path and file name */
        strcat(data, "/tmp/file.txt");
#endif
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
char * goodG2B2Source(char * data)
{
    if(goodG2B2Global)
    {
#ifdef _WIN32
        /* FIX: Use a fixed, full path and file name */
        strcat(data, "c:\\temp\\file.txt");
#else
        /* FIX: Use a fixed, full path and file name */
        strcat(data, "/tmp/file.txt");
#endif
    }
    return data;
}

#endif /* OMITGOOD */

} /* close namespace */