/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_ncat_65a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: ncat
 *    BadSink : Copy string to data using wcsncat
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE665_Improper_Initialization__wchar_t_ncat_65b_goodG2BSink(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = CWE665_Improper_Initialization__wchar_t_ncat_65b_goodG2BSink;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FIX: Properly initialize data */
    data[0] = L'\0'; /* null terminate */
    funcPtr(data);
}

void CWE665_Improper_Initialization__wchar_t_ncat_65_good()
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
    CWE665_Improper_Initialization__wchar_t_ncat_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
