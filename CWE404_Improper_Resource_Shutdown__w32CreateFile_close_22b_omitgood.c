/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22b.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: close
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using close()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_badGlobal;

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_badSink(HANDLE data)
{
    if(CWE404_Improper_Resource_Shutdown__w32CreateFile_close_22_badGlobal)
    {
        if (data != INVALID_HANDLE_VALUE)
        {
            /* FLAW: Attempt to close the file using close() instead of CloseHandle() */
            _close((int)data);
        }
    }
}

#endif /* OMITBAD */

