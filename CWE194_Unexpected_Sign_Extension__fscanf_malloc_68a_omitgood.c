/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fscanf_malloc_68a.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sink: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

short CWE194_Unexpected_Sign_Extension__fscanf_malloc_68_badData;
short CWE194_Unexpected_Sign_Extension__fscanf_malloc_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE194_Unexpected_Sign_Extension__fscanf_malloc_68b_badSink();

void CWE194_Unexpected_Sign_Extension__fscanf_malloc_68_bad()
{
    short data;
    /* Initialize data */
    data = 0;
    /* FLAW: Use a value input from the console using fscanf() */
    fscanf (stdin, "%hd", &data);
    CWE194_Unexpected_Sign_Extension__fscanf_malloc_68_badData = data;
    CWE194_Unexpected_Sign_Extension__fscanf_malloc_68b_badSink();
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
    CWE194_Unexpected_Sign_Extension__fscanf_malloc_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif