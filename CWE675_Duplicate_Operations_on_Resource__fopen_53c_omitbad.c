/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_53c.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: fopen Open and close a file using fopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE675_Duplicate_Operations_on_Resource__fopen_53d_goodG2BSink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_53c_goodG2BSink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_53d_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE675_Duplicate_Operations_on_Resource__fopen_53d_goodB2GSink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_53c_goodB2GSink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_53d_goodB2GSink(data);
}

#endif /* OMITGOOD */