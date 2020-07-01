/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_fputs_01.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: fputs
 *    GoodSink: Check if fputws() fails
 *    BadSink : Do not check if fputws() fails
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#ifndef OMITGOOD

static void good1()
{
    /* FIX: check the return value */
    if (fputws(L"string", stdout) == WEOF)
    {
        printLine("fputws failed!");
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_fputs_01_good()
{
    good1();
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
    CWE252_Unchecked_Return_Value__wchar_t_fputs_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif