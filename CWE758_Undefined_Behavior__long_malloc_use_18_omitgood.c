/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__long_malloc_use_18.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: malloc_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from malloc without initialization
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE758_Undefined_Behavior__long_malloc_use_18_bad()
{
    goto sink;
sink:
    {
        long * pointer = (long *)malloc(sizeof(long));
        if (pointer == NULL) {exit(-1);}
        long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
        free(pointer);
        printLongLine(data);
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
    CWE758_Undefined_Behavior__long_malloc_use_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
