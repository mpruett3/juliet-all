/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_68a.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

int CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_68_badData;
int CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_68_goodG2BData;


#ifndef OMITGOOD

/* good function declarations */
void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_68_goodG2BData = data;
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_68b_goodG2BSink();
}

void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_68_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

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
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
