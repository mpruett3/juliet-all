/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file descriptor using open()
 * Sinks:
 *    GoodSink: Close the file before reusing the file descriptor
 *    BadSink : Reassign the file descriptor before closing the file
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
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

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_badGlobal;

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_badSink(int data)
{
    if(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_badGlobal)
    {
        /* FLAW: Assign data to another file descriptor without closing the descriptor from the source */
        data = OPEN("BadSink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        /* avoid incidental for not closing the file */
        if (data != -1)
        {
            CLOSE(data);
        }
    }
}

#endif /* OMITBAD */

