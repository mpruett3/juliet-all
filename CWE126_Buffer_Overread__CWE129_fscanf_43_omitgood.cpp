/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_fscanf_43.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE126_Buffer_Overread__CWE129_fscanf_43
{

#ifndef OMITBAD

static void badSource(int &data)
{
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
}

void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    badSource(data);
    {
        int buffer[10] = { 0 };
        /* POTENTIAL FLAW: Attempt to access an index of the array that is above the upper bound
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE126_Buffer_Overread__CWE129_fscanf_43; /* so that we can use good and bad easily */

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