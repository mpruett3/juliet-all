/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_file_ofstream_22b.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-22b.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed file name
 * Sink: ofstream
 *    BadSink : Open the file named in data using ofstream::open()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
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

namespace CWE23_Relative_Path_Traversal__char_file_ofstream_22
{

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
extern int badGlobal;

char * badSource(char * data)
{
    if(badGlobal)
    {
        {
            /* Read input from a file */
            size_t dataLen = strlen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if (FILENAME_MAX-dataLen > 1)
            {
                pFile = fopen(FILENAME, "r");
                if (pFile != NULL)
                {
                    /* POTENTIAL FLAW: Read data from a file */
                    if (fgets(data+dataLen, (int)(FILENAME_MAX-dataLen), pFile) == NULL)
                    {
                        printLine("fgets() failed");
                        /* Restore NUL terminator if fgets fails */
                        data[dataLen] = '\0';
                    }
                    fclose(pFile);
                }
            }
        }
    }
    return data;
}

#endif /* OMITBAD */


} /* close namespace */