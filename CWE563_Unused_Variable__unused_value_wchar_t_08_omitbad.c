/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_wchar_t_08.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-08.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}


#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second staticReturnsTrue() to staticReturnsFalse() */
static void goodB2G1()
{
    wchar_t data;
    if(staticReturnsTrue())
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = L'W';
    }
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use data without over-writing its value */
        printf("%02lx\n", data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    wchar_t data;
    if(staticReturnsTrue())
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = L'W';
    }
    if(staticReturnsTrue())
    {
        /* FIX: Use data without over-writing its value */
        printf("%02lx\n", data);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first staticReturnsTrue() to staticReturnsFalse() */
static void goodG2B1()
{
    wchar_t data;
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Initialize and use data before it is overwritten */
        data = L'W';
        printf("%02lx\n", data);
    }
    if(staticReturnsTrue())
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = L'Z';
        printf("%02lx\n", data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    wchar_t data;
    if(staticReturnsTrue())
    {
        /* FIX: Initialize and use data before it is overwritten */
        data = L'W';
        printf("%02lx\n", data);
    }
    if(staticReturnsTrue())
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = L'Z';
        printf("%02lx\n", data);
    }
}

void CWE563_Unused_Variable__unused_value_wchar_t_08_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE563_Unused_Variable__unused_value_wchar_t_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif