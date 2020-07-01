/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Addition_of_Data_Structure_Sentinel__basic_64a.c
Label Definition File: CWE464_Addition_of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 464 Addition of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sinks:
 *    BadSink : Place data into and print an array
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE464_Addition_of_Data_Structure_Sentinel__basic_64b_badSink(void * dataVoidPtr);

void CWE464_Addition_of_Data_Structure_Sentinel__basic_64_bad()
{
    char data;
    data = ' ';
    {
        char charArraySource[2];
        charArraySource[0] = (char)getc(stdin);
        charArraySource[1] = '\0';
        /* FLAW: If the character entered on the command line is not an int,
         * a null value will be returned */
        data = (char)atoi(charArraySource);
    }
    CWE464_Addition_of_Data_Structure_Sentinel__basic_64b_badSink(&data);
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
    CWE464_Addition_of_Data_Structure_Sentinel__basic_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
