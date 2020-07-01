/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_22b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define HELLO_STRING L"hello"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_22_badGlobal;

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_22_badSink(size_t data)
{
    if(CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_22_badGlobal)
    {
        {
            wchar_t * myString;
            /* POTENTIAL FLAW: No MAXIMUM limitation for memory allocation, but ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > wcslen(HELLO_STRING))
            {
                myString = (wchar_t *)malloc(data*sizeof(wchar_t));
                if (myString == NULL) {exit(-1);}
                /* Copy a small string into myString */
                wcscpy(myString, HELLO_STRING);
                printWLine(myString);
                free(myString);
            }
            else
            {
                printLine("Input is less than the length of the source string");
            }
        }
    }
}

#endif /* OMITBAD */

