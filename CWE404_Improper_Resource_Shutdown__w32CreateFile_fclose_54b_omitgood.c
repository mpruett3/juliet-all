/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: fclose
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c_badSink(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54b_badSink(HANDLE data)
{
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_54c_badSink(data);
}

#endif /* OMITBAD */
