/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE526_Info_Exposure_Environment_Variables__basic_12.c
Label Definition File: CWE526_Info_Exposure_Environment_Variables__basic.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 526 Information Exposure Through Environment Variables
 * Sinks:
 *    GoodSink: Print a generic error message to the console
 *    BadSink : Expose the contents of an environment variable to the console
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE526_Info_Exposure_Environment_Variables__basic_12_bad()
{
    if(globalReturnsTrueOrFalse())
    {
        /* FLAW: environment variable exposed */
        printLine(getenv("PATH"));
    }
    else
    {
        /* FIX: error message is general */
        printLine("Not in path");
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
    CWE526_Info_Exposure_Environment_Variables__basic_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
