/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61a.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
FILE * CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61b_badSource(FILE * data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61_bad()
{
    FILE * data;
    data = NULL;
    data = CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61b_badSource(data);
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
