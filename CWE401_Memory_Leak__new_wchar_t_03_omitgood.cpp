/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_wchar_t_03.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-03.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_wchar_t_03
{

#ifndef OMITBAD

void bad()
{
    wchar_t * data;
    data = NULL;
    if(5==5)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new wchar_t;
        /* Initialize and make use of data */
        *data = L'A';
        printHexCharLine((char)*data);
    }
    if(5==5)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_wchar_t_03; /* so that we can use good and bad easily */

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
