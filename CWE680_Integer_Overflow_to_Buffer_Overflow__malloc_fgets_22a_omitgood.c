/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_22a.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_22_badGlobal = 0;

int CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_22_badSource(int data);

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_22_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_22_badGlobal = 1; /* true */
    data = CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_22_badSource(data);
    {
        size_t i;
        int *intPointer;
        /* POTENTIAL FLAW: if data * sizeof(int) > SIZE_MAX, overflows to a small value
         * so that the for loop doing the initialization causes a buffer overflow */
        intPointer = (int*)malloc(data * sizeof(int));
        if (intPointer == NULL) {exit(-1);}
        for (i = 0; i < (size_t)data; i++)
        {
            intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
        }
        printIntLine(intPointer[0]);
        free(intPointer);
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
