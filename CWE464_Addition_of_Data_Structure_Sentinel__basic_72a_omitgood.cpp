/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Addition_of_Data_Structure_Sentinel__basic_72a.cpp
Label Definition File: CWE464_Addition_of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-72a.tmpl.cpp
*/
/*
 * @description
 * CWE: 464 Addition of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sinks:
 *    BadSink : Place data into and print an array
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE464_Addition_of_Data_Structure_Sentinel__basic_72
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(vector<char> dataVector);

void bad()
{
    char data;
    vector<char> dataVector;
    data = ' ';
    {
        char charArraySource[2];
        charArraySource[0] = (char)getc(stdin);
        charArraySource[1] = '\0';
        /* FLAW: If the character entered on the command line is not an int,
         * a null value will be returned */
        data = (char)atoi(charArraySource);
    }
    /* Put data in a vector */
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    badSink(dataVector);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE464_Addition_of_Data_Structure_Sentinel__basic_72; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif