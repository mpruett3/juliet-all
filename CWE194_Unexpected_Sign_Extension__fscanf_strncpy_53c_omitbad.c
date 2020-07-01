/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fscanf_strncpy_53c.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sink: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


#ifndef OMITGOOD

/* good function declaration */
void CWE194_Unexpected_Sign_Extension__fscanf_strncpy_53d_goodG2BSink(short data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE194_Unexpected_Sign_Extension__fscanf_strncpy_53c_goodG2BSink(short data)
{
    CWE194_Unexpected_Sign_Extension__fscanf_strncpy_53d_goodG2BSink(data);
}

#endif /* OMITGOOD */