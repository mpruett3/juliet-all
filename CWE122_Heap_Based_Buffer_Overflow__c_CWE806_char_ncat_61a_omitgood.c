/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_61a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncat
 *    BadSink : Copy data to string using strncat
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_61b_badSource(char * data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_61_bad()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_61b_badSource(data);
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than sizeof(dest)-strlen(dest)*/
        strncat(dest, data, strlen(data));
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
        free(data);
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif