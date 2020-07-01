/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_declare_67b.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete_array.label.xml
Template File: sources-sink-67b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_declare_67
{

typedef struct _structType
{
    int64_t * structFirst;
} structType;

#ifndef OMITBAD

void badSink(structType myStruct)
{
    int64_t * data = myStruct.structFirst;
    printLongLongLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITBAD */


} /* close namespace */