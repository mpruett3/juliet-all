/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_12.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fprintf
 *    GoodSink: Correctly check if fwprintf() failed
 *    BadSink : Incorrectly check if fwprintf() failed
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: check for the correct return value */
        if (fwprintf(stdout, L"%s\n", L"string") < 0)
        {
            printLine("fwprintf failed!");
        }
    }
    else
    {
        /* FIX: check for the correct return value */
        if (fwprintf(stdout, L"%s\n", L"string") < 0)
        {
            printLine("fwprintf failed!");
        }
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_12_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fprintf_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif