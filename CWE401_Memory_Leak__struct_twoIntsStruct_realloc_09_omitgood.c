/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoIntsStruct_realloc_09.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE401_Memory_Leak__struct_twoIntsStruct_realloc_09_bad()
{
    struct _twoIntsStruct * data;
    data = NULL;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = (struct _twoIntsStruct *)realloc(data, 100*sizeof(struct _twoIntsStruct));
        if (data == NULL) {exit(-1);}
        /* Initialize and make use of data */
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine((twoIntsStruct *)&data[0]);
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
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
    CWE401_Memory_Leak__struct_twoIntsStruct_realloc_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif