/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_rand_22b.c
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE126_Buffer_Overread__CWE129_rand_22_badGlobal;

void CWE126_Buffer_Overread__CWE129_rand_22_badSink(int data)
{
    if(CWE126_Buffer_Overread__CWE129_rand_22_badGlobal)
    {
        {
            int buffer[10] = { 0 };
            /* POTENTIAL FLAW: Attempt to access an index of the array that is above the upper bound
             * This check does not check the upper bounds of the array index */
            if (data >= 0)
            {
                printIntLine(buffer[data]);
            }
            else
            {
                printLine("ERROR: Array index is negative");
            }
        }
    }
}

#endif /* OMITBAD */

