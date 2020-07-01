/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_05.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: w32CreateMutex
 *    GoodSink: Correctly check if CreateMutexW() failed
 *    BadSink : Incorrectly check if CreateMutexW() failed
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#include <windows.h>
#define BUFFER_SIZE 1024

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_05_bad()
{
    if(staticTrue)
    {
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexW(NULL, FALSE, NULL);
            /* FLAW: If CreateMutexW() failed, the return value will be NULL,
               but we are checking to see if the return value is INVALID_HANDLE_VALUE */
            if (hMutex == INVALID_HANDLE_VALUE)
            {
                exit(1);
            }
            /* We'll leave out most of the implementation since it has nothing to do with the CWE
             * and since the checkers are looking for certain function calls anyway */
            CloseHandle(hMutex);
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
    CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
