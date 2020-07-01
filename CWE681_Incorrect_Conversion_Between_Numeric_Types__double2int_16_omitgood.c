/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE681_Incorrect_Conversion_Between_Numeric_Types__double2int_16.c
Label Definition File: CWE681_Incorrect_Conversion_Between_Numeric_Types.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 681 Incorrect Conversion Between Numeric Types
 * Sinks: double2int
 *    GoodSink: check for conversion error
 *    BadSink : explicit cast
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE 256

#ifndef OMITBAD

void CWE681_Incorrect_Conversion_Between_Numeric_Types__double2int_16_bad()
{
    while(1)
    {
        {
            char inputBuffer[CHAR_ARRAY_SIZE];
            double doubleNumber = 0;
            /* Enter: 1e20f, result should be 2147483647 (for bad case) */
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
            printIntLine((int)doubleNumber);
        }
        break;
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
    CWE681_Incorrect_Conversion_Between_Numeric_Types__double2int_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif