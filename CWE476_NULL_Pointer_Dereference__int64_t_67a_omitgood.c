/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__int64_t_67a.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE476_NULL_Pointer_Dereference__int64_t_67_structType
{
    int64_t * structFirst;
} CWE476_NULL_Pointer_Dereference__int64_t_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE476_NULL_Pointer_Dereference__int64_t_67b_badSink(CWE476_NULL_Pointer_Dereference__int64_t_67_structType myStruct);

void CWE476_NULL_Pointer_Dereference__int64_t_67_bad()
{
    int64_t * data;
    CWE476_NULL_Pointer_Dereference__int64_t_67_structType myStruct;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    myStruct.structFirst = data;
    CWE476_NULL_Pointer_Dereference__int64_t_67b_badSink(myStruct);
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
    CWE476_NULL_Pointer_Dereference__int64_t_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
