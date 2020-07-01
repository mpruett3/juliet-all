/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_fwrite_65a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__rand_fwrite_65b_badSink(int count);

void CWE400_Resource_Exhaustion__rand_fwrite_65_bad()
{
    int count;
    /* define a function pointer */
    void (*funcPtr) (int) = CWE400_Resource_Exhaustion__rand_fwrite_65b_badSink;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Set count to a random value */
    count = RAND32();
    /* use the function pointer */
    funcPtr(count);
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
    CWE400_Resource_Exhaustion__rand_fwrite_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
