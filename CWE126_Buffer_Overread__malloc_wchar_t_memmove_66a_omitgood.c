/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_wchar_t_memmove_66a.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE126_Buffer_Overread__malloc_wchar_t_memmove_66b_badSink(wchar_t * dataArray[]);

void CWE126_Buffer_Overread__malloc_wchar_t_memmove_66_bad()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    data = NULL;
    /* FLAW: Use a small buffer */
    data = (wchar_t *)malloc(50*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    wmemset(data, L'A', 50-1); /* fill with 'A's */
    data[50-1] = L'\0'; /* null terminate */
    /* put data in array */
    dataArray[2] = data;
    CWE126_Buffer_Overread__malloc_wchar_t_memmove_66b_badSink(dataArray);
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
    CWE126_Buffer_Overread__malloc_wchar_t_memmove_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif