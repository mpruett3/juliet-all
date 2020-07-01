/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__new_fixed_22b.cpp
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__new.label.xml
Template File: sources-sink-22b.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fixed Fixed value that will cause an integer overflow in the sink
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__new_fixed_22
{

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
extern int badGlobal;

int badSource(int data)
{
    if(badGlobal)
    {
        /* FLAW: Set data to a value that will cause an integer overflow in the call to new[] in the sink */
        data = INT_MAX / 2 + 2; /* 1073741825 */
        /* NOTE: This value will cause the sink to only allocate 4 bytes of memory, however
         * the for loop will attempt to access indices 0-1073741824 */
    }
    return data;
}

#endif /* OMITBAD */


} /* close namespace */
