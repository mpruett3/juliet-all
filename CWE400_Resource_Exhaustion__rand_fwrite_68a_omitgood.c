/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_fwrite_68a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

int CWE400_Resource_Exhaustion__rand_fwrite_68_badData;
int CWE400_Resource_Exhaustion__rand_fwrite_68_goodG2BData;
int CWE400_Resource_Exhaustion__rand_fwrite_68_goodB2GData;

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__rand_fwrite_68b_badSink();

void CWE400_Resource_Exhaustion__rand_fwrite_68_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Set count to a random value */
    count = RAND32();
    CWE400_Resource_Exhaustion__rand_fwrite_68_badData = count;
    CWE400_Resource_Exhaustion__rand_fwrite_68b_badSink();
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
    CWE400_Resource_Exhaustion__rand_fwrite_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
