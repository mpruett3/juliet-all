/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__wchar_t_declare_cpy_45.c
Label Definition File: CWE124_Buffer_Underwrite.stack.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: cpy
 *    BadSink : Copy string to data using wcscpy
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static wchar_t * CWE124_Buffer_Underwrite__wchar_t_declare_cpy_45_badData;
static wchar_t * CWE124_Buffer_Underwrite__wchar_t_declare_cpy_45_goodG2BData;


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    wchar_t * data = CWE124_Buffer_Underwrite__wchar_t_declare_cpy_45_goodG2BData;
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with 'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        wcscpy(data, source);
        printWLine(data);
    }
}

static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    wmemset(dataBuffer, L'A', 100-1);
    dataBuffer[100-1] = L'\0';
    /* FIX: Set data pointer to the allocated memory buffer */
    data = dataBuffer;
    CWE124_Buffer_Underwrite__wchar_t_declare_cpy_45_goodG2BData = data;
    goodG2BSink();
}

void CWE124_Buffer_Underwrite__wchar_t_declare_cpy_45_good()
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
    CWE124_Buffer_Underwrite__wchar_t_declare_cpy_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif