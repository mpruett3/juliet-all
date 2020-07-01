/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_remove_12.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: remove
 *    GoodSink: Check if remove() fails
 *    BadSink : Do not check if remove() fails
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define REMOVE _wremove
#else
#define REMOVE remove
#endif

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__wchar_t_remove_12_bad()
{
    if(globalReturnsTrueOrFalse())
    {
        /* FLAW: Do not check the return value */
        REMOVE(L"removemebad.txt");
    }
    else
    {
        /* FIX: check the return value */
        if (REMOVE(L"removemegood.txt") != 0)
        {
            printLine("remove failed!");
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
    CWE252_Unchecked_Return_Value__wchar_t_remove_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
