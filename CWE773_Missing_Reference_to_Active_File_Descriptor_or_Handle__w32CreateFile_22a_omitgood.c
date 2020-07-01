/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22a.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using CreateFile()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_badGlobal = 0;

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_badSink(HANDLE data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_bad()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Create a file handle using CreateFile() that may not be closed properly */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_badGlobal = 1; /* true */
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_badSink(data);
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif