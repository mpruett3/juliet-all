/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_fgets_08.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-08.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Less than CHAR_MAX
 * Sink:
 *    BadSink : Convert data to a char
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

/* Must be at least 8 for atoi() to work properly */
#define CHAR_ARRAY_SIZE 8

/* The two function below always return the same value, so a tool
 * should be able to identify that calls to the functions will always
 * return a fixed value.
 */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE197_Numeric_Truncation_Error__short_fgets_08_bad()
{
    short data;
    /* Initialize data */
    data = -1;
    if(staticReturnsTrue())
    {
        {
            char inputBuffer[CHAR_ARRAY_SIZE] = "";
            /* FLAW: Use a number input from the console using fgets() */
            if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
            {
                /* Convert to short */
                data = (short)atoi(inputBuffer);
            }
            else
            {
                printLine("fgets() failed.");
            }
        }
    }
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
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
    CWE197_Numeric_Truncation_Error__short_fgets_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
