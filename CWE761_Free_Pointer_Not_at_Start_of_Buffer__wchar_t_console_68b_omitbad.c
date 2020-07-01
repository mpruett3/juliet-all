/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_console_68b.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * BadSource: console Read input from the console
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR L'S'

extern wchar_t * CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_console_68_badDataForBadSink;

extern wchar_t * CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_console_68_badDataForGoodSink;


#ifndef OMITGOOD

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_console_68b_goodB2GSink()
{
    wchar_t * data = CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_console_68_badDataForGoodSink;
    {
        size_t i;
        /* FIX: Use a loop variable to traverse through the string pointed to by data */
        for (i=0; i < wcslen(data); i++)
        {
            if (data[i] == SEARCH_CHAR)
            {
                printLine("We have a match!");
                break;
            }
        }
        free(data);
    }
}

#endif /* OMITGOOD */