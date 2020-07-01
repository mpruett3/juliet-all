/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_connect_socket_84a.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with new [] and check the size of the memory to be allocated
 *    BadSink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_connect_socket_84.h"

namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_connect_socket_84
{

#ifndef OMITBAD

void bad()
{
    size_t data;
    /* Initialize data */
    data = 0;
    CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_connect_socket_84_bad * badObject = new CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_connect_socket_84_bad(data);
    delete badObject;
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_connect_socket_84; /* so that we can use good and bad easily */

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