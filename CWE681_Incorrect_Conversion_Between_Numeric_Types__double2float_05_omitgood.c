/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_05.c
Label Definition File: CWE681_Incorrect_Conversion_Between_Numeric_Types.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 681 Incorrect Conversion Between Numeric Types
 * Sinks: double2float
 *    GoodSink: check for conversion error
 *    BadSink : explicit cast
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <float.h>
#define CHAR_ARRAY_SIZE 256

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_05_bad()
{
    if(staticTrue)
    {
        {
            char inputBuffer[CHAR_ARRAY_SIZE];
            double doubleNumber = 0;
            /* Enter: 1e-50, result should be 0.0 (for bad case)
             *
             * Note: alternate input
             * 999999999999999999999999999999999999999999999999999999999999999
             */
            if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
            {
                /* Read a double */
                doubleNumber = atof(inputBuffer);
            }
            else
            {
                printLine("fgets() failed.");
            }
            /* FLAW: should not cast without checking if conversion is safe */
            printFloatLine((float)doubleNumber);
        }
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
    CWE681_Incorrect_Conversion_Between_Numeric_Types__double2float_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
