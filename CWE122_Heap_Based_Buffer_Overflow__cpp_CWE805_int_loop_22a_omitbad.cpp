/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_22a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-22a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: loop
 *    BadSink : Copy int array to data using a loop
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_22
{


#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the source functions. Since they are in
a C++ namespace, they don't need globally unique names. */
int goodG2B1Global = 0;
int goodG2B2Global = 0;

/* goodG2B1() - use goodsource and badsink by setting the global variable to false instead of true */
int * goodG2B1Source(int * data);

static void goodG2B1()
{
    int * data;
    data = NULL;
    goodG2B1Global = 0; /* false */
    data = goodG2B1Source(data);
    {
        int source[100] = {0}; /* fill with 0's */
        {
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printIntLine(data[0]);
            delete [] data;
        }
    }
    ;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
int * goodG2B2Source(int * data);

static void goodG2B2()
{
    int * data;
    data = NULL;
    goodG2B2Global = 1; /* true */
    data = goodG2B2Source(data);
    {
        int source[100] = {0}; /* fill with 0's */
        {
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printIntLine(data[0]);
            delete [] data;
        }
    }
    ;
}

void good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_loop_22; /* so that we can use good and bad easily */

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