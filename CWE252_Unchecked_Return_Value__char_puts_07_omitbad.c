/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_puts_07.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: puts
 *    GoodSink: Check if puts() fails
 *    BadSink : Do not check if puts() fails
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
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

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;


#ifndef OMITGOOD

/* good1() uses if(staticFive!=5) instead of if(staticFive==5) */
static void good1()
{
    if(staticFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: check the return value */
        if (PUTS("string") == EOF)
        {
            printLine("puts failed!");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticFive==5)
    {
        /* FIX: check the return value */
        if (PUTS("string") == EOF)
        {
            printLine("puts failed!");
        }
    }
}

void CWE252_Unchecked_Return_Value__char_puts_07_good()
{
    good1();
    good2();
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
    CWE252_Unchecked_Return_Value__char_puts_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif