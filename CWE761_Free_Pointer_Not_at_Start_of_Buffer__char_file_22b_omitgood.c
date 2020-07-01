/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_file_22b.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * BadSource: file Read input from a file
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR 'S'

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_file_22_badGlobal;

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_file_22_badSink(char * data)
{
    if(CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_file_22_badGlobal)
    {
        /* FLAW: We are incrementing the pointer in the loop - this will cause us to free the
         * memory block not at the start of the buffer */
        for (; *data != '\0'; data++)
        {
            if (*data == SEARCH_CHAR)
            {
                printLine("We have a match!");
                break;
            }
        }
        free(data);
    }
}

#endif /* OMITBAD */
