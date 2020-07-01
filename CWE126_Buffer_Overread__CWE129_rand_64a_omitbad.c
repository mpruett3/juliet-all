/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_rand_64a.c
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE126_Buffer_Overread__CWE129_rand_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    CWE126_Buffer_Overread__CWE129_rand_64b_goodG2BSink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE126_Buffer_Overread__CWE129_rand_64b_goodB2GSink(void * dataVoidPtr);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    CWE126_Buffer_Overread__CWE129_rand_64b_goodB2GSink(&data);
}

void CWE126_Buffer_Overread__CWE129_rand_64_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE126_Buffer_Overread__CWE129_rand_64_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif