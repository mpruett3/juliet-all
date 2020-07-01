/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_63a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-63a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: cat
 *    BadSink : Copy string to data using strcat
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__char_cat_63b_goodG2BSink(char * * data);

static void goodG2B()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    /* FIX: Properly initialize data */
    data[0] = '\0'; /* null terminate */
    CWE665_Improper_Initialization__char_cat_63b_goodG2BSink(&data);
}

void CWE665_Improper_Initialization__char_cat_63_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE665_Improper_Initialization__char_cat_63_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif