/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using fopen()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static FILE * CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_badData;
static FILE * CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    FILE * data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_badData;
    /* FLAW: Point data to another file handle without closing the handle from the source */
    data = fopen("BadSink_fopen.txt", "w+");
    /* avoid incidental for not closing the file handle */
    if (data != NULL)
    {
        fclose(data);
    }
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_bad()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Create a file handle using fopen() that may not be closed properly */
    data = fopen("BadSource_fopen.txt", "w+");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_badData = data;
    badSink();
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
