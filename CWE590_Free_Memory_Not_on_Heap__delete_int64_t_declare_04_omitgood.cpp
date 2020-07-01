/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_int64_t_declare_04.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-04.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

namespace CWE590_Free_Memory_Not_on_Heap__delete_int64_t_declare_04
{

#ifndef OMITBAD

void bad()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    if(STATIC_CONST_TRUE)
    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            int64_t dataBuffer;
            dataBuffer = 5LL;
            data = &dataBuffer;
        }
    }
    printLongLongLine(*data);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete data;
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE590_Free_Memory_Not_on_Heap__delete_int64_t_declare_04; /* so that we can use good and bad easily */

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