/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_badGlobal;

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_badSink(FILE * data)
{
    if(CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_badGlobal)
    {
        /* FLAW: No attempt to close the file */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

