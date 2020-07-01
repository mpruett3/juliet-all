/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_61b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: fopen Open and close a file using fopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

FILE * CWE675_Duplicate_Operations_on_Resource__fopen_61b_badSource(FILE * data)
{
    data = fopen("BadSource_fopen.txt", "w+");
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
    return data;
}

#endif /* OMITBAD */

