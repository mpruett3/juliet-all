/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__new_wchar_t_cpy_83a.cpp
Label Definition File: CWE127_Buffer_Underread__new.label.xml
Template File: sources-sink-83a.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: cpy
 *    BadSink : Copy data to string using wcscpy
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__new_wchar_t_cpy_83.h"

namespace CWE127_Buffer_Underread__new_wchar_t_cpy_83
{

#ifndef OMITBAD

void bad()
{
    wchar_t * data;
    data = NULL;
    CWE127_Buffer_Underread__new_wchar_t_cpy_83_bad badObject(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE127_Buffer_Underread__new_wchar_t_cpy_83; /* so that we can use good and bad easily */

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