/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_printf_61a.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifndef OMITBAD

/* bad function declaration */
char * CWE134_Uncontrolled_Format_String__char_environment_printf_61b_badSource(char * data);

void CWE134_Uncontrolled_Format_String__char_environment_printf_61_bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    data = CWE134_Uncontrolled_Format_String__char_environment_printf_61b_badSource(data);
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    printf(data);
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
    CWE134_Uncontrolled_Format_String__char_environment_printf_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif