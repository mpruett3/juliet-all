/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the source functions. */
int CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22_goodG2B1Global = 0;
int CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22_goodG2B2Global = 0;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22_goodG2B1Source(wchar_t * data);

static void goodG2B1()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22_goodG2B1Global = 0; /* false */
    data = CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22_goodG2B1Source(data);
    {
        wchar_t dest[50] = L"";
        size_t i, dataLen;
        dataLen = wcslen(data);
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        for (i = 0; i < dataLen; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22_goodG2B2Source(wchar_t * data);

static void goodG2B2()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22_goodG2B2Global = 1; /* true */
    data = CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22_goodG2B2Source(data);
    {
        wchar_t dest[50] = L"";
        size_t i, dataLen;
        dataLen = wcslen(data);
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        for (i = 0; i < dataLen; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_22_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif