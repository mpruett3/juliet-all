/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_54d.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: w32_close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__fopen_w32_close_54e_badSink(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_54d_badSink(FILE * data)
{
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_54e_badSink(data);
}

#endif /* OMITBAD */
