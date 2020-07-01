/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_fgets_22b.c
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE127_Buffer_Underread__CWE839_fgets_22_badGlobal;

void CWE127_Buffer_Underread__CWE839_fgets_22_badSink(int data)
{
    if(CWE127_Buffer_Underread__CWE839_fgets_22_badGlobal)
    {
        {
            int buffer[10] = { 0 };
            /* POTENTIAL FLAW: Attempt to access a negative index of the array
             * This check does not check to see if the array index is negative */
            if (data < 10)
            {
                printIntLine(buffer[data]);
            }
            else
            {
                printLine("ERROR: Array index is too big.");
            }
        }
    }
}

#endif /* OMITBAD */

