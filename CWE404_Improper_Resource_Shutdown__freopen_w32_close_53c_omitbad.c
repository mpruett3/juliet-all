/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32_close_53c.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: w32_close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__freopen_w32_close_53d_goodB2GSink(FILE * data);

void CWE404_Improper_Resource_Shutdown__freopen_w32_close_53c_goodB2GSink(FILE * data)
{
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_53d_goodB2GSink(data);
}

#endif /* OMITGOOD */