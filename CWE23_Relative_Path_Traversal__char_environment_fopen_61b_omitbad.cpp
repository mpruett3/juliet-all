/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_environment_fopen_61b.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed file name
 * Sinks: fopen
 *    BadSink : Open the file named in data using fopen()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH "/tmp/"
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifdef _WIN32
#define FOPEN fopen
#else
#define FOPEN fopen
#endif

namespace CWE23_Relative_Path_Traversal__char_environment_fopen_61
{


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
char * goodG2BSource(char * data)
{
    /* FIX: Use a fixed file name */
    strcat(data, "file.txt");
    return data;
}

#endif /* OMITGOOD */

} /* close namespace */
