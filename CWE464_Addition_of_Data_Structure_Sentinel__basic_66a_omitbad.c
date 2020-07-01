/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Addition_of_Data_Structure_Sentinel__basic_66a.c
Label Definition File: CWE464_Addition_of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 464 Addition of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sinks:
 *    BadSink : Place data into and print an array
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE464_Addition_of_Data_Structure_Sentinel__basic_66b_goodG2BSink(char dataArray[]);

static void goodG2B()
{
    char data;
    char dataArray[5];
    data = ' ';
    /* FIX: Set data to be a char */
    data = 'a';
    dataArray[2] = data;
    CWE464_Addition_of_Data_Structure_Sentinel__basic_66b_goodG2BSink(dataArray);
}

void CWE464_Addition_of_Data_Structure_Sentinel__basic_66_good()
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
    CWE464_Addition_of_Data_Structure_Sentinel__basic_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
