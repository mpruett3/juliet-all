/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_negative_32.c
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * BadSource: negative Negative index value
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE127_Buffer_Underread__CWE839_negative_32_bad()
{
    int data;
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    /* Initialize data */
    data = -1;
    {
        int data = *dataPtr1;
        /* POTENTIAL FLAW: Use an invalid index */
        data = -5;
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
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


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__CWE839_negative_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif