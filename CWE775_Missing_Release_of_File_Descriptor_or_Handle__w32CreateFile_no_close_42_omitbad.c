/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_42.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <windows.h>


#ifndef OMITGOOD

static HANDLE goodB2GSource(HANDLE data)
{
    /* POTENTIAL FLAW: Open a file without closing it */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    return data;
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = goodB2GSource(data);
    /* FIX: If the file is still opened, close it */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_42_good()
{
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif