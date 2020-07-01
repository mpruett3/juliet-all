/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE526_Info_Exposure_Environment_Variables__basic_03.c
Label Definition File: CWE526_Info_Exposure_Environment_Variables__basic.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 526 Information Exposure Through Environment Variables
 * Sinks:
 *    GoodSink: Print a generic error message to the console
 *    BadSink : Expose the contents of an environment variable to the console
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE526_Info_Exposure_Environment_Variables__basic_03_bad()
{
    if(5==5)
    {
        /* FLAW: environment variable exposed */
        printLine(getenv("PATH"));
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE526_Info_Exposure_Environment_Variables__basic_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
