/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__malloc_char_loop_22b.c
Label Definition File: CWE124_Buffer_Underwrite__malloc.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: loop
 *    BadSink : Copy string to data using a loop
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
extern int CWE124_Buffer_Underwrite__malloc_char_loop_22_badGlobal;

char * CWE124_Buffer_Underwrite__malloc_char_loop_22_badSource(char * data)
{
    if(CWE124_Buffer_Underwrite__malloc_char_loop_22_badGlobal)
    {
        {
            char * dataBuffer = (char *)malloc(100*sizeof(char));
            if (dataBuffer == NULL) {exit(-1);}
            memset(dataBuffer, 'A', 100-1);
            dataBuffer[100-1] = '\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = dataBuffer - 8;
        }
    }
    return data;
}

#endif /* OMITBAD */

