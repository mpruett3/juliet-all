/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Addition_of_Data_Structure_Sentinel__basic_62b.cpp
Label Definition File: CWE464_Addition_of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 464 Addition of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sinks:
 *    BadSink : Place data into and print an array
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE464_Addition_of_Data_Structure_Sentinel__basic_62
{


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(char &data)
{
    /* FIX: Set data to be a char */
    data = 'a';
}

#endif /* OMITGOOD */

} /* close namespace */
