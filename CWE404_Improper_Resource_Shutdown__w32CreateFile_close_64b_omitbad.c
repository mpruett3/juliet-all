/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: close
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using close()
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>


#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_64b_goodB2GSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    HANDLE * dataPtr = (HANDLE *)dataVoidPtr;
    /* dereference dataPtr into data */
    HANDLE data = (*dataPtr);
    if (data != INVALID_HANDLE_VALUE)
    {
        /* FIX: Close the file using CloseHandle() */
        CloseHandle(data);
    }
}

#endif /* OMITGOOD */
