/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__long_09.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__long_09_bad()
{
    long * data;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Set data to NULL */
        data = NULL;
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        printLongLine(*data);
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
    CWE476_NULL_Pointer_Dereference__long_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif