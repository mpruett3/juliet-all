/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Addition_of_Data_Structure_Sentinel__basic_32.c
Label Definition File: CWE464_Addition_of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 464 Addition of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sink:
 *    BadSink : Place data into and print an array
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char data;
    char *dataPtr1 = &data;
    char *dataPtr2 = &data;
    data = ' ';
    {
        char data = *dataPtr1;
        /* FIX: Set data to be a char */
        data = 'a';
        *dataPtr1 = data;
    }
    {
        char data = *dataPtr2;
        {
            char charArraySink[4];
            charArraySink[0] = 'x';
            /* POTENTIAL FLAW: If data is null, the rest of the array will not be printed */
            charArraySink[1] = data;
            charArraySink[2] = 'z';
            charArraySink[3] = '\0';
            printLine(charArraySink);
        }
    }
}

void CWE464_Addition_of_Data_Structure_Sentinel__basic_32_good()
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
    CWE464_Addition_of_Data_Structure_Sentinel__basic_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
