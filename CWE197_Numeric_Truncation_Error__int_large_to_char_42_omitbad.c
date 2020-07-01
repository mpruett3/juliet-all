/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_large_to_char_42.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-42.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than SHRT_MAX
 * GoodSource: Less than CHAR_MAX
 * Sink: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

static int goodG2BSource(int data)
{
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    return data;
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    data = goodG2BSource(data);
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}

void CWE197_Numeric_Truncation_Error__int_large_to_char_42_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

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
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE197_Numeric_Truncation_Error__int_large_to_char_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif