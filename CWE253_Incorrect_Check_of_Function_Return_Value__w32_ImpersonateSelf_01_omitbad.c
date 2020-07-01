/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_01.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: ImpersonateSelf
 *    GoodSink: Correctly check if ImpersonateSelf() fails
 *    BadSink : Incorrectly check if ImpersonateSelf() fails
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32")


#ifndef OMITGOOD

static void good1()
{
    /* FIX: check for the correct return value */
    if (!ImpersonateSelf(SecurityImpersonation))
    {
        exit(1);
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_01_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__w32_ImpersonateSelf_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
