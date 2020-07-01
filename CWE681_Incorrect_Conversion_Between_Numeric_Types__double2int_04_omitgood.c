/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE681_Incorrect_Conversion_Between_Numeric_Types__double2int_04.c
Label Definition File: CWE681_Incorrect_Conversion_Between_Numeric_Types.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 681 Incorrect Conversion Between Numeric Types
 * Sinks: double2int
 *    GoodSink: check for conversion error
 *    BadSink : explicit cast
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE 256

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE681_Incorrect_Conversion_Between_Numeric_Types__double2int_04_bad()
{
    if(STATIC_CONST_TRUE)
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
    CWE681_Incorrect_Conversion_Between_Numeric_Types__double2int_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif