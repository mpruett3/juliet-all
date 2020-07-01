/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int_realloc_21.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-21.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The static variable below is used to drive control flow in the sink function */
static int badStatic = 0;

static void badSink(int * data)
{
    if(badStatic)
    {
        /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
        data[0] = 5;
        printIntLine(data[0]);
        free(data);
    }
}

void CWE690_NULL_Deref_From_Return__int_realloc_21_bad()
{
    int * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (int *)realloc(data, 1*sizeof(int));
    badStatic = 1; /* true */
    badSink(data);
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
    CWE690_NULL_Deref_From_Return__int_realloc_21_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
