/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_07.c
Label Definition File: CWE126_Buffer_Overread__CWE170.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Sinks: memcpy
 *    GoodSink: Copy a string using memcpy with explicit null termination
 *    BadSink : Copy a string using memcpy without explicit null termination
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;


#ifndef OMITGOOD

/* good1() uses if(staticFive!=5) instead of if(staticFive==5) */
static void good1()
{
    if(staticFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            memcpy(dest, data, 99*sizeof(wchar_t));
            dest[99] = L'\0'; /* FIX: null terminate dest */
            printWLine(dest);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticFive==5)
    {
        {
            wchar_t data[150], dest[100];
            /* Initialize data */
            wmemset(data, L'A', 149);
            data[149] = L'\0';
            memcpy(dest, data, 99*sizeof(wchar_t));
            dest[99] = L'\0'; /* FIX: null terminate dest */
            printWLine(dest);
        }
    }
}

void CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_07_good()
{
    good1();
    good2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE126_Buffer_Overread__CWE170_wchar_t_memcpy_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif