/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Addition_of_Data_Structure_Sentinel__basic_22b.c
Label Definition File: CWE464_Addition_of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 464 Addition of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sink:
 *    BadSink : Place data into and print an array
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE464_Addition_of_Data_Structure_Sentinel__basic_22_badGlobal;

char CWE464_Addition_of_Data_Structure_Sentinel__basic_22_badSource(char data)
{
    if(CWE464_Addition_of_Data_Structure_Sentinel__basic_22_badGlobal)
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
    return data;
}

#endif /* OMITBAD */

