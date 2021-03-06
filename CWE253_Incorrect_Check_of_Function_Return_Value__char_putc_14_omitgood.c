/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_14.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: putc
 *    GoodSink: Correctly check if putc() failed
 *    BadSink : Incorrectly check if putc() failed
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_14_bad()
{
    if(globalFive==5)
    {
        /* FLAW: putc() might fail, in which case the return value will be EOF (-1), but
         * we are checking to see if the return value is 0 */
        if (putc((int)'A', stdout) == 0)
        {
            printLine("putc failed!");
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_putc_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
