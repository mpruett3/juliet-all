/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_fwrite_52b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fscanf_fwrite_52c_goodG2BSink(int count);

void CWE400_Resource_Exhaustion__fscanf_fwrite_52b_goodG2BSink(int count)
{
    CWE400_Resource_Exhaustion__fscanf_fwrite_52c_goodG2BSink(count);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fscanf_fwrite_52c_goodB2GSink(int count);

void CWE400_Resource_Exhaustion__fscanf_fwrite_52b_goodB2GSink(int count)
{
    CWE400_Resource_Exhaustion__fscanf_fwrite_52c_goodB2GSink(count);
}

#endif /* OMITGOOD */