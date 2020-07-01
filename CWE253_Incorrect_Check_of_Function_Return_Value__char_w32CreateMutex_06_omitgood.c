/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_06.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: w32CreateMutex
 *    GoodSink: Correctly check if CreateMutexA() failed
 *    BadSink : Incorrectly check if CreateMutexA() failed
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#include <windows.h>
#define BUFFER_SIZE 1024

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_06_bad()
{
    if(STATIC_CONST_FIVE==5)
    {
        {
            HANDLE hMutex = NULL;
            hMutex = CreateMutexA(NULL, FALSE, NULL);
            /* FLAW: If CreateMutexA() failed, the return value will be NULL,
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_w32CreateMutex_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
