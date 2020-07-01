/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE526_Info_Exposure_Environment_Variables__basic_05.c
Label Definition File: CWE526_Info_Exposure_Environment_Variables__basic.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 526 Information Exposure Through Environment Variables
 * Sinks:
 *    GoodSink: Print a generic error message to the console
 *    BadSink : Expose the contents of an environment variable to the console
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE526_Info_Exposure_Environment_Variables__basic_05_bad()
{
    if(staticTrue)
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
    CWE526_Info_Exposure_Environment_Variables__basic_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
