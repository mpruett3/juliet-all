/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__negative_memmove_54a.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-54a.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sink: memmove
 *    BadSink : Copy strings using memmove() with the length of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE194_Unexpected_Sign_Extension__negative_memmove_54b_badSink(short data);

void CWE194_Unexpected_Sign_Extension__negative_memmove_54_bad()
{
    short data;
    /* Initialize data */
    data = 0;
    /* FLAW: Use a negative number */
    data = -1;
    CWE194_Unexpected_Sign_Extension__negative_memmove_54b_badSink(data);
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
    CWE194_Unexpected_Sign_Extension__negative_memmove_54_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif