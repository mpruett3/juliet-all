/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using CreateFile() and CloseHandle()
 * GoodSource: Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

typedef struct _CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67_structType
{
    HANDLE structFirst;
} CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67_structType;

#ifndef OMITBAD

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67b_badSink(CWE675_Duplicate_Operations_on_Resource__w32CreateFile_67_structType myStruct)
{
    HANDLE data = myStruct.structFirst;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CloseHandle(data);
}

#endif /* OMITBAD */

