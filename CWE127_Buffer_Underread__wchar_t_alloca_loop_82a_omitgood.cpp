/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__wchar_t_alloca_loop_82a.cpp
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__wchar_t_alloca_loop_82.h"

namespace CWE127_Buffer_Underread__wchar_t_alloca_loop_82
{

#ifndef OMITBAD

void bad()
{
    wchar_t * data;
    wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataBuffer, L'A', 100-1);
    dataBuffer[100-1] = L'\0';
    /* FLAW: Set data pointer to before the allocated memory buffer */
    data = dataBuffer - 8;
    CWE127_Buffer_Underread__wchar_t_alloca_loop_82_base* baseObject = new CWE127_Buffer_Underread__wchar_t_alloca_loop_82_bad;
    baseObject->action(data);
    delete baseObject;
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE127_Buffer_Underread__wchar_t_alloca_loop_82; /* so that we can use good and bad easily */

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