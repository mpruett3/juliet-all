/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__long_45.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static long * CWE476_NULL_Pointer_Dereference__long_45_badData;
static long * CWE476_NULL_Pointer_Dereference__long_45_goodG2BData;
static long * CWE476_NULL_Pointer_Dereference__long_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    long * data = CWE476_NULL_Pointer_Dereference__long_45_badData;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLine(*data);
}

void CWE476_NULL_Pointer_Dereference__long_45_bad()
{
    long * data;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    CWE476_NULL_Pointer_Dereference__long_45_badData = data;
    badSink();
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
    CWE476_NULL_Pointer_Dereference__long_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
