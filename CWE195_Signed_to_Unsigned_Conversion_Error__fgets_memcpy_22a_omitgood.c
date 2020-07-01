/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_22a.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_22_badGlobal = 0;

int CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_22_badSource(int data);

void CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_22_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_22_badGlobal = 1; /* true */
    data = CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_22_badSource(data);
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign conversion could result in a very large number */
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
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
    CWE195_Signed_to_Unsigned_Conversion_Error__fgets_memcpy_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif