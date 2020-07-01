/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_fwrite_65a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(count) + 2)

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__fgets_fwrite_65b_badSink(int count);

void CWE400_Resource_Exhaustion__fgets_fwrite_65_bad()
{
    int count;
    /* define a function pointer */
    void (*funcPtr) (int) = CWE400_Resource_Exhaustion__fgets_fwrite_65b_badSink;
    /* Initialize count */
    count = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* POTENTIAL FLAW: Read count from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            count = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    /* use the function pointer */
    funcPtr(count);
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
    CWE400_Resource_Exhaustion__fgets_fwrite_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
