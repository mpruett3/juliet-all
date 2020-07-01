/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__rand_memcpy_45.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: rand Set data to result of RAND32(), which could be negative
 * GoodSource: Positive integer
 * Sinks: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static short CWE194_Unexpected_Sign_Extension__rand_memcpy_45_badData;
static short CWE194_Unexpected_Sign_Extension__rand_memcpy_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    short data = CWE194_Unexpected_Sign_Extension__rand_memcpy_45_badData;
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign extension could result in a very large number */
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
    }
}

void CWE194_Unexpected_Sign_Extension__rand_memcpy_45_bad()
{
    short data;
    /* Initialize data */
    data = 0;
    /* FLAW: Use a random value that could be less than 0 */
    data = (short)RAND32();
    CWE194_Unexpected_Sign_Extension__rand_memcpy_45_badData = data;
    badSink();
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
    CWE194_Unexpected_Sign_Extension__rand_memcpy_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
