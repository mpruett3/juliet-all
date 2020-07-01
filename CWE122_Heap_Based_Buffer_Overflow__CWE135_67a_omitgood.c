/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE122_Heap_Based_Buffer_Overflow__CWE135_67_structType
{
    void * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__CWE135_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__CWE135_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__CWE135_67_structType myStruct);

void CWE122_Heap_Based_Buffer_Overflow__CWE135_67_bad()
{
    void * data;
    CWE122_Heap_Based_Buffer_Overflow__CWE135_67_structType myStruct;
    data = NULL;
    {
        wchar_t * dataBadBuffer = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (dataBadBuffer == NULL) {exit(-1);}
        wmemset(dataBadBuffer, L'A', 50-1);
        dataBadBuffer[50-1] = L'\0';
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = (void *)dataBadBuffer;
    }
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__CWE135_67b_badSink(myStruct);
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
    CWE122_Heap_Based_Buffer_Overflow__CWE135_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif