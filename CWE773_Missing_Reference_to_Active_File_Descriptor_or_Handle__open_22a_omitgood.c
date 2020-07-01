/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22a.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-22a.tmpl.c
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
int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_badGlobal = 0;

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_badSink(int data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Create a file descriptor using open() that may not be closed properly */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_badGlobal = 1; /* true */
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_badSink(data);
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
