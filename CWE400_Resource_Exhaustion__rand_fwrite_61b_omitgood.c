/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_fwrite_61b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

int CWE400_Resource_Exhaustion__rand_fwrite_61b_badSource(int count)
{
    /* POTENTIAL FLAW: Set count to a random value */
    count = RAND32();
    return count;
}

#endif /* OMITBAD */

