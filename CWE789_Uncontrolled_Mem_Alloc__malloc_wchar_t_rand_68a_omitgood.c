/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define HELLO_STRING L"hello"

size_t CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_badData;
size_t CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_goodG2BData;
size_t CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_goodB2GData;

#ifndef OMITBAD

/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68b_badSink();

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_bad()
{
    size_t data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Set data to a random value */
    data = rand();
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_badData = data;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68b_badSink();
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_rand_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif