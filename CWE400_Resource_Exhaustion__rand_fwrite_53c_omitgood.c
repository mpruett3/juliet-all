/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_fwrite_53c.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__rand_fwrite_53d_badSink(int count);

void CWE400_Resource_Exhaustion__rand_fwrite_53c_badSink(int count)
{
    CWE400_Resource_Exhaustion__rand_fwrite_53d_badSink(count);
}

#endif /* OMITBAD */

