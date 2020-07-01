/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72a.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-72a.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * BadSource:  Add values to the list, including the number zero
 * GoodSource: Add value to the list that are not zero
 * Sinks:
 *    GoodSink: Iterate through the list without attempting to clear its contents
 *    BadSink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>
#include <list>
#include <iostream>

using namespace std;

using namespace std;

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72
{


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<list<int> > dataVector);

static void goodG2B()
{
    list<int>  data;
    vector<list<int> > dataVector;
    /* FIX: Insert non-zero values into the list */
    data.push_back(100);
    data.push_back(200);
    /* Put data in a vector */
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    goodG2BSink(dataVector);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<list<int> > dataVector);

static void goodB2G()
{
    list<int>  data;
    vector<list<int> > dataVector;
    /* POTENTIAL FLAW: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    dataVector.insert(dataVector.end(), 1, data);
    goodB2GSink(dataVector);
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

using namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_72; /* so that we can use good and bad easily */

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