/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_12.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * Sinks: type_overrun_memmove
 *    GoodSink: Perform the memmove() and prevent overwriting part of the structure
 *    BadSink : Overwrite part of the structure by incorrectly using the sizeof(struct) in memmove()
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* SRC_STR is 32 wchar_t long, including the null terminator, for 64-bit architectures */
#define SRC_STR L"0123456789abcdef0123456789abcde"

typedef struct _charVoid
{
    wchar_t charFirst[16];
    void * voidSecond;
    void * voidThird;
} charVoid;


#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            charVoid structCharVoid;
            structCharVoid.voidSecond = (void *)SRC_STR;
            /* Print the initial block pointed to by structCharVoid.voidSecond */
            printWLine((wchar_t *)structCharVoid.voidSecond);
            /* FIX: Use sizeof(structCharVoid.charFirst) to avoid overwriting the pointer voidSecond */
            memmove(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
            structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)structCharVoid.charFirst);
            printWLine((wchar_t *)structCharVoid.voidSecond);
        }
    }
    else
    {
        {
            charVoid structCharVoid;
            structCharVoid.voidSecond = (void *)SRC_STR;
            /* Print the initial block pointed to by structCharVoid.voidSecond */
            printWLine((wchar_t *)structCharVoid.voidSecond);
            /* FIX: Use sizeof(structCharVoid.charFirst) to avoid overwriting the pointer voidSecond */
            memmove(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
            structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(wchar_t))-1] = L'\0'; /* null terminate the string */
            printWLine((wchar_t *)structCharVoid.charFirst);
            printWLine((wchar_t *)structCharVoid.voidSecond);
        }
    }
}

void CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_12_good()
{
    good1();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif