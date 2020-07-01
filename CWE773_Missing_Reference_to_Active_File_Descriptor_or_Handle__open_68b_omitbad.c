/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file descriptor using open()
 * Sinks:
 *    GoodSink: Close the file before reusing the file descriptor
 *    BadSink : Reassign the file descriptor before closing the file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

extern int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_badDataForBadSink;

extern int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_badDataForGoodSink;


#ifndef OMITGOOD

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b_goodB2GSink()
{
    int data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_badDataForGoodSink;
    /* FIX: Close the file from the source before reassigning data to a new file descriptor */
    if (data != -1)
    {
        CLOSE(data);
    }
    data = OPEN("GoodSink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* avoid incidental for not closing the file */
    if (data != -1)
    {
        CLOSE(data);
    }
}

#endif /* OMITGOOD */