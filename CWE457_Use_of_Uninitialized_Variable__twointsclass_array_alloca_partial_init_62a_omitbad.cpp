/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_array_alloca_partial_init_62a.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass_array.label.xml
Template File: sources-sinks-62a.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: partial_init Initialize part, but not all of the array
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_alloca_partial_init_62
{


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSource(TwoIntsClass * &data);

static void goodG2B()
{
    TwoIntsClass * data;
    data = reinterpret_cast<TwoIntsClass *>(ALLOCA(10*sizeof(TwoIntsClass)));
    goodG2BSource(data);
    /* POTENTIAL FLAW: Use data without initializing it */
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].intOne);
        printIntLine(data[i].intTwo);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSource(TwoIntsClass * &data);

static void goodB2G()
{
    TwoIntsClass * data;
    data = reinterpret_cast<TwoIntsClass *>(ALLOCA(10*sizeof(TwoIntsClass)));
    goodB2GSource(data);
    /* FIX: Ensure data is initialized before use */
    for(int i=0; i<10; i++)
    {
        data[i].intOne = i;
        data[i].intTwo = i;
    }
    for(int i=0; i<10; i++)
    {
        printIntLine(data[i].intOne);
        printIntLine(data[i].intTwo);
    }
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_alloca_partial_init_62; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif