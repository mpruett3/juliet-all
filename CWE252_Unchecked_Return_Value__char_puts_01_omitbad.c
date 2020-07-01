/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_puts_01.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: puts
 *    GoodSink: Check if puts() fails
 *    BadSink : Do not check if puts() fails
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define PUTS puts
#else
#define PUTS puts
#endif


#ifndef OMITGOOD

static void good1()
{
    /* FIX: check the return value */
    if (PUTS("string") == EOF)
    {
        printLine("puts failed!");
    }
}

void CWE252_Unchecked_Return_Value__char_puts_01_good()
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
    CWE252_Unchecked_Return_Value__char_puts_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif