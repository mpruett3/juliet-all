/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_13.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fputs
 *    GoodSink: Correctly check if fputws() failed
 *    BadSink : Incorrectly check if fputws() failed
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_13_bad()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        /* FLAW: fputws() might fail, in which case the return value will be WEOF (-1), but
         * we are checking to see if the return value is 0 */
        if (fputws(L"string", stdout) == 0)
        {
            printLine("fputws failed!");
        }
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
    CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_fputs_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
