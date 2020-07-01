/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE681_Incorrect_Conversion_Between_Numeric_Types__double2int_08.c
Label Definition File: CWE681_Incorrect_Conversion_Between_Numeric_Types.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 681 Incorrect Conversion Between Numeric Types
 * Sinks: double2int
 *    GoodSink: check for conversion error
 *    BadSink : explicit cast
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE 256

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE681_Incorrect_Conversion_Between_Numeric_Types__double2int_08_bad()
{
    if(staticReturnsTrue())
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
    CWE681_Incorrect_Conversion_Between_Numeric_Types__double2int_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
