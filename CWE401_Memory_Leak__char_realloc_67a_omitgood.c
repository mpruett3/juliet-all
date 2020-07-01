/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__char_realloc_67a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE401_Memory_Leak__char_realloc_67_structType
{
    char * structFirst;
} CWE401_Memory_Leak__char_realloc_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE401_Memory_Leak__char_realloc_67b_badSink(CWE401_Memory_Leak__char_realloc_67_structType myStruct);

void CWE401_Memory_Leak__char_realloc_67_bad()
{
    char * data;
    CWE401_Memory_Leak__char_realloc_67_structType myStruct;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (char *)realloc(data, 100*sizeof(char));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    myStruct.structFirst = data;
    CWE401_Memory_Leak__char_realloc_67b_badSink(myStruct);
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
    CWE401_Memory_Leak__char_realloc_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
