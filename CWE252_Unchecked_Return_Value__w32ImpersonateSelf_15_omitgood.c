/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15.c
Label Definition File: CWE252_Unchecked_Return_Value__w32ImpersonateSelf.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks:
 *    GoodSink: Check the return value of ImpersonateSelf() and handle it properly
 *    BadSink : Do not check if ImpersonateSelf() fails
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32")

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15_bad()
{
    switch(6)
    {
    case 6:
        /* FLAW: Do not check if ImpersonateSelf() fails */
        ImpersonateSelf(SecurityImpersonation);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif