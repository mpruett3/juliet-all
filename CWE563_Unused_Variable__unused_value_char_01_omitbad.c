/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_char_01.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-01.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char data;
    /* FIX: Initialize and use data before it is overwritten */
    data = 'C';
    printHexCharLine(data);
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data = 'Z';
    printHexCharLine(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    char data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 'C';
    /* FIX: Use data without over-writing its value */
    printHexCharLine(data);
}

void CWE563_Unused_Variable__unused_value_char_01_good()
{
    goodG2B();
    goodB2G();
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
    CWE563_Unused_Variable__unused_value_char_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif