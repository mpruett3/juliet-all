/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__malloc_realloc_wchar_t_15.c
Label Definition File: CWE401_Memory_Leak__malloc_realloc.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Sinks:
 *    GoodSink: Ensure the memory block pointed to by data is always freed
 *    BadSink : malloc() and use then realloc() and use data before free()
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

void CWE401_Memory_Leak__malloc_realloc_wchar_t_15_bad()
{
    switch(6)
    {
    case 6:
    {
        wchar_t * data = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        /* Initialize and make use of data */
        wcscpy(data, L"A String");
        printWLine(data);
        /* FLAW: If realloc() fails, the initial memory block will not be freed() */
        data = (wchar_t *)realloc(data, (130000)*sizeof(wchar_t));
        if (data != NULL)
        {
            /* Reinitialize and make use of data */
            wcscpy(data, L"New String");
            printWLine(data);
            free(data);
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
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
    CWE401_Memory_Leak__malloc_realloc_wchar_t_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif