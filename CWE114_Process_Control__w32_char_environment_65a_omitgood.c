/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_environment_65a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: environment Read input from an environment variable
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#include <windows.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE114_Process_Control__w32_char_environment_65b_badSink(char * data);

void CWE114_Process_Control__w32_char_environment_65_bad()
{
    char * data;
    /* define a function pointer */
    void (*funcPtr) (char *) = CWE114_Process_Control__w32_char_environment_65b_badSink;
    char dataBuffer[100] = "";
    data = dataBuffer;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = strlen(data);
        char * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* POTENTIAL FLAW: Read data from an environment variable */
            strncat(data+dataLen, environment, 100-dataLen-1);
        }
    }
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITBAD */


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
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_char_environment_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif