/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__wchar_t_type_overrun_memcpy_04.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Sinks: type_overrun_memcpy
 *    GoodSink: Perform the memcpy() and prevent overwriting part of the structure
 *    BadSink : Overwrite part of the structure by incorrectly using the sizeof(struct) in memcpy()
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define SRC_STR L"0123456789abcdef0123456789abcde"

typedef struct _charVoid
{
    wchar_t charFirst[16];
    void * voidSecond;
    void * voidThird;
} charVoid;

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__wchar_t_type_overrun_memcpy_04_bad()
{
    if(STATIC_CONST_TRUE)
    {
        {
            charVoid * structCharVoid = (charVoid *)malloc(sizeof(charVoid));
            if (structCharVoid == NULL) {exit(-1);}
            structCharVoid->voidSecond = (void *)SRC_STR;
            /* Print the initial block pointed to by structCharVoid->voidSecond */
            printWLine((wchar_t *)structCharVoid->voidSecond);
            /* FLAW: Use the sizeof(*structCharVoid) which will overwrite the pointer y */
            memcpy(structCharVoid->charFirst, SRC_STR, sizeof(*structCharVoid));
            structCharVoid->charFirst[(sizeof(structCharVoid->charFirst)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)structCharVoid->charFirst);
            printWLine((wchar_t *)structCharVoid->voidSecond);
            free(structCharVoid);
        }
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
    CWE122_Heap_Based_Buffer_Overflow__wchar_t_type_overrun_memcpy_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif