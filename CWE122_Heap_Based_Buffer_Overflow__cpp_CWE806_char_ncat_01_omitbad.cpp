/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_char_ncat_01.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806.label.xml
Template File: sources-sink-01.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: ncat
 *    BadSink : Copy data to string using strncat
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_char_ncat_01
{


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    data = new char[100];
    /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    memset(data, 'A', 50-1); /* fill with 'A's */
    data[50-1] = '\0'; /* null terminate */
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than sizeof(dest)-strlen(dest)*/
        strncat(dest, data, strlen(data));
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
        delete [] data;
    }
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_char_ncat_01; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif