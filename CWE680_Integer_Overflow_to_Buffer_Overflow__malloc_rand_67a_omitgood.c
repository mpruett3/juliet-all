/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67a.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_structType
{
    int structFirst;
} CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67b_badSink(CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_structType myStruct);

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_bad()
{
    int data;
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    myStruct.structFirst = data;
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67b_badSink(myStruct);
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
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif