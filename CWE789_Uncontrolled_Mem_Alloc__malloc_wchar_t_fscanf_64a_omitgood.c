/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_64a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define HELLO_STRING L"hello"

#ifndef OMITBAD

/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_64b_badSink(void * dataVoidPtr);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_64_bad()
{
    size_t data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%zu", &data);
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_64b_badSink(&data);
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fscanf_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif