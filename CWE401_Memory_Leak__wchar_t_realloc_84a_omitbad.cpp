/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_realloc_84a.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE401_Memory_Leak__wchar_t_realloc_84.h"

namespace CWE401_Memory_Leak__wchar_t_realloc_84
{


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    CWE401_Memory_Leak__wchar_t_realloc_84_goodG2B * goodG2BObject = new CWE401_Memory_Leak__wchar_t_realloc_84_goodG2B(data);
    delete goodG2BObject;
}

/* goodG2B uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    data = NULL;
    CWE401_Memory_Leak__wchar_t_realloc_84_goodB2G * goodB2GObject = new CWE401_Memory_Leak__wchar_t_realloc_84_goodB2G(data);
    delete goodB2GObject;
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

using namespace CWE401_Memory_Leak__wchar_t_realloc_84; /* so that we can use good and bad easily */

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