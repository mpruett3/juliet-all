/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22a.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
int CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22_badGlobal = 0;

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22_badSink(HANDLE data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22_bad()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22_badGlobal = 1; /* true */
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22_badSink(data);
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
