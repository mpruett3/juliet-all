/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_char_memmove_65a.c
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE126_Buffer_Overread__malloc_char_memmove_65b_goodG2BSink(char * data);

static void goodG2B()
{
    char * data;
    void (*funcPtr) (char *) = CWE126_Buffer_Overread__malloc_char_memmove_65b_goodG2BSink;
    data = NULL;
    /* FIX: Use a large buffer */
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1); /* fill with 'A's */
    data[100-1] = '\0'; /* null terminate */
    funcPtr(data);
}

void CWE126_Buffer_Overread__malloc_char_memmove_65_good()
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
    CWE126_Buffer_Overread__malloc_char_memmove_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
