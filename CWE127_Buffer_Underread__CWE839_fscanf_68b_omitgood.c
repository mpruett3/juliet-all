/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_fscanf_68b.c
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE127_Buffer_Underread__CWE839_fscanf_68_badData;
extern int CWE127_Buffer_Underread__CWE839_fscanf_68_goodG2BData;
extern int CWE127_Buffer_Underread__CWE839_fscanf_68_goodB2GData;

#ifndef OMITBAD

void CWE127_Buffer_Underread__CWE839_fscanf_68b_badSink()
{
    int data = CWE127_Buffer_Underread__CWE839_fscanf_68_badData;
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

#endif /* OMITBAD */

