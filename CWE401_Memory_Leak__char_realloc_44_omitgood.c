/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__char_realloc_44.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

static void badSink(char * data)
{
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

void CWE401_Memory_Leak__char_realloc_44_bad()
{
    char * data;
    /* define a function pointer */
    void (*funcPtr) (char *) = badSink;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (char *)realloc(data, 100*sizeof(char));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    /* use the function pointer */
    funcPtr(data);
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
    CWE401_Memory_Leak__char_realloc_44_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
