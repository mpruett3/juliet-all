/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Addition_of_Data_Structure_Sentinel__basic_03.c
Label Definition File: CWE464_Addition_of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-03.tmpl.c
*/
/*
 * @description
 * CWE: 464 Addition of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sink:
 *    BadSink : Place data into and print an array
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE464_Addition_of_Data_Structure_Sentinel__basic_03_bad()
{
    char data;
    data = ' ';
    if(5==5)
    {
        {
            char charArraySource[2];
            charArraySource[0] = (char)getc(stdin);
            charArraySource[1] = '\0';
            /* FLAW: If the character entered on the command line is not an int,
             * a null value will be returned */
            data = (char)atoi(charArraySource);
        }
    }
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
    CWE464_Addition_of_Data_Structure_Sentinel__basic_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
